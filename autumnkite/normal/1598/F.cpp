#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> m(n);
    std::vector<std::vector<int>> mn(n), c(n);
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        m[i] = s.size();
        int now = 0;
        mn[i].resize(m[i] + 1), c[i].resize(m[i] + 1);
        for (int j = 0; j < m[i]; ++j) {
            if (s[j] == '(') {
                ++now;
            } else {
                --now;
            }
            if (now < mn[i][j]) {
                mn[i][j + 1] = now;
                c[i][j + 1] = 1;
            } else if (mn[i][j] == now) {
                mn[i][j + 1] = now;
                c[i][j + 1] = c[i][j] + 1;
            } else {
                mn[i][j + 1] = mn[i][j];
                c[i][j + 1] = c[i][j];
            }
        }
        d[i] = now;
    }

    std::vector<int> sum(1 << n);
    for (int i = 0; i < n; ++i) {
        sum[1 << i] = d[i];
    }
    for (int S = 1; S < (1 << n); ++S) {
        sum[S] = sum[S & (S - 1)] + sum[S & -S];
    }

    std::vector<int> f(1 << n, -1);
    f[0] = 0;
    for (int S = 1; S < (1 << n); ++S) {
        for (int i = 0; i < n; ++i) {
            int v = sum[S ^ (1 << i)] + mn[i][m[i]];
            if (S >> i & 1 && f[S ^ (1 << i)] >= 0 && v >= 0) {
                f[S] = std::max(f[S], f[S ^ (1 << i)]
                                      + (v == 0 ? c[i][m[i]] : 0));
            }
        }
    }
    int ans = 0;
    for (int S = 0; S < (1 << n); ++S) {
        if (f[S] >= 0) {
            ans = std::max(ans, f[S]);
            for (int i = 0; i < n; ++i) {
                if (!(S >> i & 1)) {
                    int p = std::upper_bound(mn[i].begin(), mn[i].end(), 
                                             -sum[S], std::greater<int>())
                            - mn[i].begin() - 1;
                    ans = std::max(ans, f[S]
                                        + (mn[i][p] == -sum[S] ? c[i][p] : 0));
                }
            }
        }
    }
    std::cout << ans << "\n";
}