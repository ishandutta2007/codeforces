#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
int dp[maxn][9];
int good[9][9];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << '\n';
        exit(0);
    }
    if (n >= 4) {
        cout << -1 << '\n';
        return 0;
    }
    vector < string > a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        int cnt = 0;
        for (int pos = 0; pos < n; ++pos) {
            int d = (mask&(1 << pos));
            if (d > 0) d = 1;
            if (a[pos][0] != char('0' + d)) cnt++;
        }
        dp[0][mask] = cnt;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int lst = 0; lst < (1 << n); ++lst) {
            int s1 = (mask&1) + (lst&1), s2 = ((mask>>1)&1) + ((lst>>1)&1), s3 = ((mask>>2)&1) + ((lst>>2)&1);
            if (n == 2 && (s1 + s2) % 2 == 1) good[mask][lst] = 1;
            if (n == 3 && (s1 + s2) % 2 == 1 && (s2 + s3) % 2 == 1) good[mask][lst] = 1;
        }
    }
    for (int j = 1; j < m; ++j) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            int goal = 0;
            dp[j][mask] = n * m + 1;
            for (int pos = 0; pos < n; ++pos) {
                int d = (mask&(1 << pos));
                if (d > 0) d = 1;
                if (a[pos][j] != char('0' + d)) goal++;
            }
            for (int lst = 0; lst < (1 << n); ++lst) {
                if (good[mask][lst]) {
                    dp[j][mask] = min(dp[j][mask], dp[j - 1][lst] + goal);
                }
            }
        }
    }
    int ans = dp[m - 1][0];
    for (int i = 0; i < (1 << n); ++i) ans = min(ans, dp[m - 1][i]);
    if (ans == n * m + 1) {
        cout << -1;
        exit(0);
    }
    cout << ans << '\n';
    return 0;
}