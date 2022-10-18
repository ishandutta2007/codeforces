#include <bits/stdc++.h>

using namespace std;

int a[200005];
int dp[200005][2];
int inf = 1e9 + 1e8;

void solve() {
    int h, n;
    cin >> h >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    //a[n + 1] = 0;
    //++n;
    vector < pair < int, int > > q;
    for (int i = 1; i <= n; ++i) {
        int j = i + 1;
        while (j <= n && a[j] == a[j - 1] - 1) ++j;
        q.push_back({i, j - 1});
        i = j - 1;
    }
    int f = q[0].second - q[0].first + 1;
    if (f == 1) dp[0][0] = 0, dp[0][1] = inf;
    else dp[0][0] = (1^(f % 2)), dp[0][1] = f % 2;
    //cout << dp[0][0] << " " << dp[0][1] << '\n';
    for (int i = 1; i < (int)q.size(); ++i) {
        dp[i][0] = inf;
        dp[i][1] = inf;
        f = q[i].second - q[i].first + 1;
        if (f % 2 == 1) {
            dp[i][0] = min({dp[i][0], dp[i - 1][0] + 1, dp[i - 1][1] + 2});
            //cout << f << " " << dp[i - 1][0] << " " << dp[i - 1][1] + 1 << '\n';
            dp[i][1] = min({dp[i][1], dp[i - 1][0], dp[i - 1][1] + 1});
        }
        else {
            dp[i][0] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1] + 1});
            dp[i][1] = min({dp[i][1], dp[i - 1][0] + 1, dp[i - 1][1] + 2});
        }
        //cout << dp[i][0] << " " << dp[i][1] << '\n';
    }
    int add = 0;
    if (a[n] + 1 == 2) add = 1;
    cout << min(dp[(int)q.size() - 1][0], dp[(int)q.size() - 1][1] + 1 - add) << '\n';
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}