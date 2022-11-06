#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    for(; n > 0; --n) {
        std::cin >> s;
        if(s.length() <= 10) {
            std::cout << s;
        } else {
            std::cout << s.substr(0, 1) << s.length() - 2 << s.substr(s.length() - 1, 1);
        }
        std::cout << "\n";
    }
    return 0;
}