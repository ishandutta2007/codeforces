#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<long long> sum(n), sum2(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            sum[i] += a[i][j];
            sum2[i] += 1ll * a[i][j] * a[i][j];
        }
    }

    std::vector<long long> tmp;
    for (int i = 1; i < n; ++i) {
        tmp.push_back(sum[i] - sum[i - 1]);
    }
    std::nth_element(tmp.begin(), tmp.begin() + n / 2, tmp.end());
    long long delta = tmp[n / 2];
    int p = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (sum[i] - sum[i - 1] != delta) {
            p = i;
            break;
        }
    }

    long long d = delta - (sum[p] - sum[p - 1]);
    long long t = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (p < i - 1 || p > i + 1) {
            t = 2 * sum2[i] - sum2[i - 1] - sum2[i + 1];
            break;
        }
    }

    for (int i = 0; i < m; ++i) {
        long long nsum2 = sum2[p];
        nsum2 -= 1ll * a[p][i] * a[p][i];
        nsum2 += 1ll * (a[p][i] + d) * (a[p][i] + d);
        if (2 * nsum2 - sum2[p - 1] - sum2[p + 1] == t) {
            std::cout << p << " " << a[p][i] + d << "\n";
            return 0;
        }
    }
}