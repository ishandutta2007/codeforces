#include <bits/stdc++.h>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a, --b, --c;
    int n = abs(a - b) * 2;
    if (a < n && b < n && c < n && (a + n / 2) % n == b) {
        std::cout << (c + n / 2) % n + 1 << "\n";
    } else {
        std::cout << -1 << "\n";
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