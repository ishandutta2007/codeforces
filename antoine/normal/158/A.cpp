#include <iostream>

int main() {
    int n, k;
    int count = 0;
    
    std::cin >> n;
    std::cin >> k;
    
    int a;
    for(; k >= 1; --k, --n) {
        std::cin >> a;
        if(a > 0)
            ++count;
    }
    
    int k_score = a;
    
    for(; n >= 1; --n) {
        std::cin >> a;
        if(a > 0 && a >= k_score)
            ++count;
    }
    std::cout << count;
}