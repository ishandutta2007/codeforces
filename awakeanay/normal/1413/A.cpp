#include <iostream>

#define int long long

signed main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        int a[n];
        for(int i = 0; i < n; i++)
            std::cin >> a[i];
            
        for(int i = 0; i < n; i+=2) {
            std::cout << -a[i+1] << " " << a[i] << " ";
        }
        std::cout << std::endl;
    }
}