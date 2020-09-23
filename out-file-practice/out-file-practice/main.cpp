#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    std::ifstream in_file{ "./RomeoAndJuliet.txt" }; //opening input file
    std::ofstream out_file{ "./RomeoAndJuliet_copy.txt" }; //opening output file

    if (!in_file) {
        std::cerr << "There was a problem opening the file" << std::endl;
        return 1;
    }

    if (!out_file) {
        std::cerr << "An error occurred while creating the file." << std::endl;
        return 1;
    }

    std::cout << "Copying..." << std::endl;

    std::string line{};
    int line_num{ 0 };

    while (std::getline(in_file, line)) {
        if (line == "") {
            out_file << std::endl;
        } else {
            ++line_num;
            out_file << std::setw(7) << std::left << line_num
                << line << std::endl;
        }
    }

    std::cout << "Copied " << line_num << " lines. Copy complete!" << std::endl << std::endl;

    in_file.close(); //closing read file
    out_file.close(); //closing output file

    return 0;
}