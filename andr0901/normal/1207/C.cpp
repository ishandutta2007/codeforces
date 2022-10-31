#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

const int INF = 1e18;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector <vector <int>> dp(n + 1, vector <int> (2, INF));
    dp[0][0] = b;
    forn (i, 1, n) {
        dp[i][1] = 2 * b + min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a);
        if (s[i] == '0' && s[i - 1] == '0')
            dp[i][0] = b + min(dp[i - 1][0] + a, dp[i - 1][1] + 2 * a);
        //cout << i << ": " << dp[i][0] << " " << dp[i][1] << "\n";
    }
    dp[n][0] = b + min(dp[n - 1][0] + a, dp[n - 1][1] + 2 * a);
    cout << dp[n][0] << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}