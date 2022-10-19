#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    const int MOD = 998244353;

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ranges(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    vector<int> dp(m + 1), res(m + 1);

    auto calc = [&](int x) {
        int mm = m / x;
        vector<pair<int, int>> nranges(n + 1);
        for (int i = 1; i <= n; i++) {
            nranges[i].first = ranges[i].first / x + (ranges[i].first % x != 0);
            nranges[i].second = ranges[i].second / x;
            if (nranges[i].second < nranges[i].first) return 0;
        }
        vector<vector<int>> pref(n + 1, vector<int>(mm + 1, 0));
        for (int i = 0; i <= mm; i++) {
            pref[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = nranges[i].first + i - 1; j <= mm; j++) {
                int l = max(0, j - nranges[i].second);
                int r = j - nranges[i].first;
                int tmp = pref[i - 1][r] - (l > 0 ? pref[i - 1][l - 1] : 0);
                if (tmp < 0) tmp += MOD;
                pref[i][j] = (pref[i][j - 1] + tmp) % MOD;
            }
        }
        return pref[n][mm];
    };
    for (int i = 1; i <= m; i++) {
        dp[i] = calc(i);
    };

    for (int i = m; i >= 1; i--) {
        res[i] = dp[i];
        for (int j = i + i; j <= m; j += i) {
            res[i] = (res[i] - res[j] + MOD) % MOD;
        }
    }

    cout << res[1] << '\n';

    return 0;
}