#include <iostream>
#include <cstring>
#include <algorithm>

int main() {
    int w;
    std::cin >> w;
    if(w > 2 && !(w&1))
    std::cout << "YES";
    else std::cout << "NO";
    return 0;
}