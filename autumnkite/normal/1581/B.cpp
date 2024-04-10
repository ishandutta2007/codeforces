#include <bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    if (k <= 1 || m < n - 1 || m > 1ll * n * (n - 1) / 2) {
        std::cout << "NO\n";
    } else if (k >= 4) {
        std::cout << "YES\n";
    } else if (k == 3 && m == 1ll * n * (n - 1) / 2) {
        std::cout << "YES\n";
    } else if (k == 2 && n == 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}