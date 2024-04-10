#include <bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
    for (int i = k; i < n; ++i) {
        for (int j = k; j < m - k; ++j) {
            int d = 0;
            while (i >= d && j >= d && j + d < m &&
                    a[i - d][j - d] == '*' && a[i - d][j + d] == '*') {
                ++d;
            }
            if (d > k) {
                for (int t = 0; t < d; ++t) {
                    vis[i - t][j - t] = vis[i - t][j + t] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && a[i][j] == '*') {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
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