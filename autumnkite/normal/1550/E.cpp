#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::string a;
    std::cin >> a;
    std::vector<std::vector<int>> len(k, std::vector<int>(n + 1));
    for (int c = 0; c < k; ++c) {
        for (int i = n - 1; i >= 0; --i) {
            len[c][i] = a[i] == '?' || a[i] == c + 'a' ? len[c][i + 1] + 1 : 0;
        }
    }

    auto check = [&](int L) {
        std::vector<std::vector<int>> nx(k, std::vector<int>(n + 1));
        for (int c = 0; c < k; ++c) {
            nx[c][n] = n + 1;
            for (int i = n - 1; i >= 0; --i) {
                nx[c][i] = len[c][i] >= L ? i + L : nx[c][i + 1];
            }
        }
        std::vector<int> f((1 << k), n + 1);
        f[0] = 0;
        for (int S = 1; S < (1 << k); ++S) {
            for (int i = 0; i < k; ++i) {
                if (S >> i & 1 && f[S ^ (1 << i)] <= n) {
                    f[S] = std::min(f[S], nx[i][f[S ^ (1 << i)]]);
                }
            }
        }
        return f[(1 << k) - 1] <= n;
    };

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << l << "\n";
}