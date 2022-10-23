#include <bits/stdc++.h>

using namespace std;

constexpr long long inf = numeric_limits<long long>::max() / 4;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> c(n, vector<long long>(n));
    for (auto &row : c) for (auto &e : row) cin >> e;

    vector<long long> row_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        row_sum[i + 1] += row_sum[i];
        for (int j = 0; j < n; ++j) {
            row_sum[i + 1] += c[i][j];
        }
    }

    vector<vector<long long>> sum(n + 1, vector<long long>(n + 1, 0));

    auto get_cost = [&](int l, int r) {
        return row_sum[r] - row_sum[l] - sum[l][r];
    };

    vector dp(n + 1, vector<long long>(n + 1, inf));
    vector root(n + 1, vector<int>(n + 1, -1));

    vector<int> p(n, 0);
    for (int r = 0; r <= n; ++r) {
        for (int l = r; l >= 0; --l) {
            if (l == r) {
                dp[l][r] = 0;
                continue;
            }
            sum[l][r] = sum[l + 1][r];
            for (int m = l; m < r; ++m) sum[l][r] += 2 * c[l][m];

            for (int m = l; m < r; ++m) {
                long long new_cost = dp[l][m] + dp[m + 1][r] + get_cost(l, m) + get_cost(m + 1, r);
                if (new_cost < dp[l][r]) {
                    root[l][r] = m;
                    dp[l][r] = new_cost;
                }
            }
        }
    }

    auto rec = [&](auto rec, int l, int r) -> int {
        if (l == r) return -1;
        int m = root[l][r];
        int lc = rec(rec, l, m);
        int rc = rec(rec, m + 1, r);
        if (lc >= 0) {
            p[lc] = m + 1;
        }
        if (rc >= 0) {
            p[rc] = m + 1;
        }
        return m;
    };
    rec(rec, 0, n);

    for (int i = 0; i < n; ++i) {
        cout << p[i] << " \n"[i == n - 1];
    }
    return 0;
}