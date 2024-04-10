#include <bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    if (1ll * (n & -n) * (m & -m) >= k) {
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