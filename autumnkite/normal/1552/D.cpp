#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    auto dfs = [&](auto &self, int k, int now, int x) {
        if (k == n) {
            return now == a[x];
        }
        if (k == x) {
            return self(self, k + 1, now, x);
        }
        for (int i = -1; i <= 1; ++i) {
            if (self(self, k + 1, now + i * a[k], x)) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < n; ++i) {
        if (dfs(dfs, 0, 0, i)) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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