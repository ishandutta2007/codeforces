#include <iostream>

#define int long long

signed main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        
        if(a <= b) {
            std::cout << b << std::endl;
            continue;
        }
        if(d >= c) {
            std::cout << -1 << std::endl;
            continue;
        }
        std::cout << b + (((a-b)%(c-d) != 0ll) + (a-b)/(c-d))*c << std::endl;
    }
}