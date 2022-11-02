#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int n;
int dp[maxn][4];
int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    n = s.size();
    if (n == 1) {
        cout << "0\n";
        return;
    }
    dp[1][0] = (s[0] != s[1] ? 0 : inf);
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 2;
    for (int i = 2; i < n; i++) {
        for (int e = 0; e < 4; e++)
            dp[i][e] = inf;
        for (int mask = 0; mask < 8; mask++) {
            if (s[i - 1] == s[i] && !(mask & 3))
                continue;
            if (s[i - 2] == s[i] && !(mask & 5))
                continue;
            dp[i][mask % 4] = min(dp[i][mask % 4], dp[i - 1][mask / 2] + ((mask & 1) ? 1 : 0));
        }
    }
    int ans = min(min(dp[n - 1][0], dp[n - 1][1]), min(dp[n - 1][2], dp[n - 1][3]));
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}