#include <bits/stdc++.h>

#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;

const int maxn = 5005, mod = 1000000007;
int dp[maxn][maxn];
int sum[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][0] = 1;
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (i + 1 < n) {
                dp[i][j] += dp[i + 1][j - 1];
            }
            dp[i][j] %= mod;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            sum[i] += dp[i][j]*dp[i][k-j];
            sum[i] %= mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * sum[i];
        ans %= mod;
    }
    while (q--) {
        int pos, val;
        cin >> pos >> val;
        pos--;
        ans = (ans-a[pos]*sum[pos])%mod;
        if (ans < 0) {
            ans += mod;
        }
        a[pos] = val;
        ans = (ans+a[pos]*sum[pos])%mod;
        cout << ans << '\n';
    }
    return 0;
}