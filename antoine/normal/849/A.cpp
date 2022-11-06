#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
    int n;
    int a;
    std::cin >> n >> a;
    if(!(n&1) || !(a&1)) {
        std::cout << "No";
        return 0;
    }
    while(--n > 0)
        std::cin >> a;
    std::cout << ((a&1) ? "Yes" : "No");
    return 0;
}