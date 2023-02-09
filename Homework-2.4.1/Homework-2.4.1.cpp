#include <fstream>
#include <iostream>
#include <string>

class Address {
public:
    Address(std::string city, std::string street, int building, int flat);

    std::string print_to_file() {
        std::string out = city + ", " + street + ", " + std::to_string(building) +
            ", " + std::to_string(flat);
        return out;
    }

private:
    std::string city;
    std::string street;
    int building;
    int flat;
};

Address::Address(std::string city, std::string street, int building, int flat) {
    this->city = city;
    this->street = street;
    this->building = building;
    this->flat = flat;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int num = 0, building = 0, flat = 0;
    std::string city, street;
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    if (!fin.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 0;
    }
    fin >> num;
    fout << num << std::endl;

    //  std::string *arr_address = new std::string[num];
    std::string string;
    for (int i = 0; i < num; ++i) {
        while (!fin.eof()) {
            fin >> city >> street >> building >> flat;
            Address address = Address(city, street, building, flat);
            std::string full_address = address.print_to_file();
            // arr_address[i] = full_address;
            fout << address.print_to_file() << std::endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
