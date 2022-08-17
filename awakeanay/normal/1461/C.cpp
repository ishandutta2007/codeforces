#include <iostream>
#include <iomanip>

signed main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        
        int a[n];
        for(int i = 0; i < n; i++)
            std::cin >> a[i];
            
        int check = n-1;
        while(check >= 0 && a[check] == check+1)
            check--;
        
        check++;
        
        long double prob = 1.000000;
        for(int i = 0; i < k; i++) {
            int c; long double p;
            std::cin >> c >> p;
            if(c >= check) {
                prob *= 1.000000000-p;
            }
        }
        
        if(check == 0) {
            std::cout << "1.00000000" << std::endl;
            continue;
        }
        
        std::cout << std::setprecision(10) << 1.000000000 - prob << std::endl;
    }
}