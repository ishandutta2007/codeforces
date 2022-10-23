// 
#include<iostream>

int main() {
    int n;
    std::cin >> n;
    if(n & 1) {
        std::cout << -1 << "\n";
    }
    else {
        for(int i=1;i<=n;++i) {
            std::cout << i + (i & 1) - (~i & 1) << " ";
        }
    }
}