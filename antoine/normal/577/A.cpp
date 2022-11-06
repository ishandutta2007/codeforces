#include <iostream>

int main() {
    int64_t n, x, ans;
    ans = 0;
    std::cin >> n >> x;
    for(int i = 1; i <= n; ++i)
        if(x % i == 0 && x / i <= n)
            ++ans;
    
    std::cout << ans;
    return 0;
}