#include <iostream>
#include <cmath>

int num(int n, int m) {
    if(n == 0 || m == 0)
        return 0;
    if(n == 1 && m == 1)
        return 0;
    if(n > m) return 1 + num(n - 2, m - 1);
    return 1 + num(n - 1, m - 2);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::cout << num(n, m);
    return 0;
}