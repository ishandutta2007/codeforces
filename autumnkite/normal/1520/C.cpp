#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    if (n == 2) {
        std::cout << -1 << "\n";
        return;
    }
    int now = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << now + 1 << " ";
            now += 2;
            if (now >= n * n) {
                now = 1;
            }
        }
        std::cout << "\n";
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