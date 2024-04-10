#include <bits/stdc++.h>

int n, k;

void solve() {
    std::cin >> n >> k;
    if (n < k) {
        std::cout << k - n << std::endl;
    } else if ((n - k) & 1) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}

int main() {
    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
}