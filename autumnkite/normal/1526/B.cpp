#include <bits/stdc++.h>

void solve() {
    int x;
    std::cin >> x;
    if (x > 111 * 11 - 111 - 11) {
        std::cout << "YES\n";
    } else {
        for (int i = 0; i < 10; ++i) {
            if (x >= 111 * i && (x - 111 * i) % 11 == 0) {
                std::cout << "YES\n";
                return;
            }
        }
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