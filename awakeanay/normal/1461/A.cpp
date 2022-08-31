#include <iostream>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        
        for(int i = 0; i < n; i++) {
            std::cout << (char)(('a' + (i%3))); 
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}