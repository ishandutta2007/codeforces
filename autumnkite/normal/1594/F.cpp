#include <bits/stdc++.h>

void solve() {
    long long s, n, k;
    std::cin >> s >> n >> k;
    if (s != k && s / (2 * k) * k + std::min(s % (2 * k), k - 1) >= n) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
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