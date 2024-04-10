#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;
const int MAXC = 101;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    vector<vector<int>> dp(n + 1, vector<int>(MAXC * n, INF));
    dp[0][0] = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * MAXC; j++) {
            if (dp[i][j] == INF) continue;
            dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], dp[i][j] + j * a[i] + (s - j) * b[i]);
            dp[i + 1][j + b[i]] = min(dp[i + 1][j + b[i]], dp[i][j] + j * b[i] + (s - j) * a[i]);
        }
        s += a[i] + b[i];
    }
    int ans = INF;
    for (int j = 0; j < n * MAXC; j++) ans = min(ans, dp[n][j]);
    ans *= 2;
    for (auto &c : a) ans += c * c * (n - 1);
    for (auto &c : b) ans += c * c * (n - 1);
    cout << ans << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}