#include <iostream>
#include <cstring>
#include <vector>

int main() {
    int64_t n;
    std::cin >> n;

    if(n%2 == 0) {
        std::cout << n/2;
    } else {
        std::cout << -(n+1)/2;
    }
}