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

const int maxn = 109;
int dp[maxn][maxn];
int n;
int a[maxn];
bool used[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int l = 0; l < n; l++) {
        for (int e = 0; e <= n; e++) {
            used[e] = 0;
        }
        for (int r = l; r < n; r++) {
            if (a[r] <= n) {
                used[a[r]] = 1;
            }
            for (int e = 0; e <= n; e++) {
                if (!used[e]) {
                    dp[l][r] = e + 1;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            for (int m = l + 1; m <= r; m++) {
                dp[l][r] = max(dp[l][r], dp[l][m - 1] + dp[m][r]);
            }
            ans += dp[l][r];
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}