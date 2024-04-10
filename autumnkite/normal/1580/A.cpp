#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    int ans = n * m;
    for (int l = 0; l < n; ++l) {
        std::vector<int> a(m), b(m);
        for (int i = 0; i < m; ++i) {
            if (s[l][i] == '0') {
                b[i] = 1;
            }
        }
        for (int r = l + 1; r < n; ++r) {
            if (r >= l + 4) {
                std::vector<int> sum(m);
                for (int i = 1; i < m; ++i) {
                    sum[i] = sum[i - 1] + b[i] + (s[r][i] == '0');
                }
                int mn = n * m;
                for (int i = 3; i < m; ++i) {
                    mn = std::min(mn, a[i - 3] - sum[i - 3]);
                    ans = std::min(ans, mn + sum[i - 1] + a[i]);
                }
            }
            for (int i = 0; i < m; ++i) {
                if (s[r][i] == '1') {
                    ++b[i];
                } else {
                    ++a[i];
                }
            }
        }
    }
    std::cout << ans << "\n";
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