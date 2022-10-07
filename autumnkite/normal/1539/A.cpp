#include <bits/stdc++.h>

void solve() {
    int n, x, t;
    std::cin >> n >> x >> t;
    int c = t / x;
    if (n <= c) {
        std::cout << 1ll * n * (n - 1) / 2 << "\n";
    } else {
        std::cout << 1ll * (n - c) * c + 1ll * c * (c - 1) / 2 << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}