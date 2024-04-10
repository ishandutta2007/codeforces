#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            int x;
            std::cin >> x;
            a[i] |= x << j;
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            int cnt[4] = {};
            for (int k = 0; k < n; ++k) {
                ++cnt[(a[k] >> i & 1) | (a[k] >> j & 1) << 1];
            }
            if (!cnt[0] && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    std::cout << "NO\n";
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