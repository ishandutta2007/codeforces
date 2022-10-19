#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = -1e16;
bool cmp(vector <int> &a, vector <int> &b) {
    return a[0] > b[0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p, k;
    cin >> n >> p >> k;
    vector <vector <int>> a(n, vector <int> (p + 1));
    for (int i = 0; i < n; ++i) cin >> a[i][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) cin >> a[i][j + 1];
    }
    sort(a.begin(), a.end(), cmp);
    int siz = (1 << p);
    vector <vector <int>> dp(n, vector <int> (siz, INF));
    for (int j = 0; j < p; ++j) {
        dp[0][(1 << j)] = a[0][j + 1];
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) {
        for (int mask = 0; mask < siz; ++mask) {
            int kol = 0;
            if (dp[i - 1][mask] == -INF) {
                continue;
            }
            for (int j = 0; j < p; ++j) {
                if ((mask >> j) & 1) ++kol;
            }
            if (i - kol < k) {
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + a[i][0]);
            }
            else {
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);
            }
            for (int j = 0; j < p; ++j) {
                if (!((mask >> j) & 1)) {
                    int tmp = mask + (1 << j);
                    if (dp[i][tmp] < dp[i - 1][mask] + a[i][j + 1]) {
                        dp[i][tmp] = dp[i - 1][mask] + a[i][j + 1];
                    }
                }
            }
        }
    }
    cout << dp[n - 1][(1 << p) - 1];
}