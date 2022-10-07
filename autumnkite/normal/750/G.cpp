#include <bits/stdc++.h>

int main() {
    int n = 50;
    long long s;
    std::cin >> s;
    long long ans = 0;
    for (int La = 0; La <= n; ++La) {
        for (int Lb = 0; Lb <= n; ++Lb) {
            long long x = s / ((2ll << La) + (2ll << Lb) - 3);
            if (x == 0 || std::__lg(x) + std::max(La, Lb) >= n) {
                continue;
            }
            long long t = s - x * ((2ll << La) + (2ll << Lb) - 3);
            t -= (1ll << Lb) - 1;
            int la = std::max(La - 1, 0);
            int lb = std::max(Lb - 1, 0);
            for (int c = t & 1; c <= la + lb; c += 2) {
                long long rem = (t + c) / 2;
                if (std::__lg(rem) > std::max(la, lb)) {
                    continue;
                }
                std::vector<std::array<long long, 2>> f(c + 1);
                f[0][0] = 1;
                for (int i = 0; i <= std::max(la, lb); ++i) {
                    int v = rem >> i & 1;
                    decltype(f) g(c + 1);
                    for (int j = 0; j <= c; ++j) {
                        g[j][0] += f[j][v];
                    }
                    if (i < la) {
                        for (int j = 1; j <= c; ++j) {
                            g[j][!v] += f[j - 1][!v];
                        }
                    }
                    if (i < lb) {
                        for (int j = 1; j <= c; ++j) {
                            g[j][!v] += f[j - 1][!v];
                        }
                    }
                    if (i < la && i < lb) {
                        for (int j = 2; j <= c; ++j) {
                            g[j][1] += f[j - 2][v];
                        }
                    }
                    f.swap(g);
                }
                ans += f[c][0];
            }
        }
    }
    std::cout << ans << "\n";
}