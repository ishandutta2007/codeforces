#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
vector < vector < char > > a;
vector < vector < int > > can;
vector < vector < int > > pref;
vector < vector < int > > dp;
int n, m;

void ok() {
    for (int i = 0; i < n; ++i) {
        dp.emplace_back();
        for (int j = 0; j < m; ++j) {
            dp.back().push_back(0);
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if (a[i][j] == '#') dp[i][j] = 0;
        }
    }
    if (dp[n - 1][m - 1] == 0) {
        cout << 0 << '\n';
        exit(0);
    }
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    char t;
    for (int i = 0; i < n; ++i) {
        a.emplace_back();
        for (int j = 0; j < m; ++j) {
            cin >> t;
            a.back().push_back(t);
        }
    }
    ok();
    if (n != 1 && m != 1) {
        if (a[1][0] == '#' || a[0][1] == '#') {
            cout << 1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i <= n; ++i) {
        can.emplace_back();
        pref.emplace_back();
        pref.back().push_back(0);
        for (int j = 0; j < m; ++j) {
            can.back().push_back(0);
            pref.back().push_back(0);
        }
    }
    can[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i != n - 1) can[i][j] = max(can[i][j], can[i + 1][j]);
            if (j != m - 1) can[i][j] = max(can[i][j], can[i][j + 1]);
            if (a[i][j] == '#') can[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (can[i - 1][j - 1]&dp[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;
            if (i == n && j == m) continue;
            int x1 = 0, x2 = 0;
            x1 = pref[n][j - 1] - pref[i][j - 1], x2 = pref[i - 1][m] - pref[i - 1][j];
            if (x1 + x2 == 0) {
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 2 << '\n';
    return 0;
}