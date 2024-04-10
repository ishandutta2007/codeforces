#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int b[n];
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
        if(i) b[i] += b[i-1];
    }
    
    int m;
    std::cin >> m;
    
    while(m--) {
        int x;
        std::cin >> x;
        
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l+r)/2;
            bool c = b[m] >= x;
            if(c)
                r = m;
            else
                l = m+1;
        }
        
        std::cout << l+1 << std::endl;
    }
}