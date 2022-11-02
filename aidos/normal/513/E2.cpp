#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)3e4 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, k;
int a[maxn];
ll dp[maxn][2];
ll d[maxn][2];
ll sum[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    dp[0][0] = dp[0][1] = d[0][0] = d[0][1] = -(1ll<<60);
    for(int j = 0; j < 2; j++) {
        ll cur = 0;
        for (int i = 1; i <= n; i++) {
            if(cur < 0) cur = 0;
            if(j) cur -= a[i];
            else cur += a[i];
            dp[i][j] = cur;
        }
    }

    k -= 2;
    for(int j = 0; j < k; j++) {
        for(int i = 1; i <= n; i++) {
            d[i][0] = dp[i][0];
            d[i][1] = dp[i][1];
            dp[i][0] = dp[i][1] = -(1ll<<60);
        }
        for(int k = 0; k < 2; k++) {
            for(int t = 0; t < 2; t++) {
                ll cur = -(1ll<<60);
                ll mx = -(1ll<<60);
                for(int i = 1; i <= n; i++) {
                    cur = max(cur, mx);
                    if(t) cur += a[i];
                    else cur -= a[i];
                    if(k) cur -= a[i];
                    else cur += a[i];
                    dp[i][k] = max(dp[i][k], cur);
                    mx = max(d[i][t], mx);
                }
            }
        }
    }
    ll ans = 0;
    for(int j = 0; j < 2; j++) {
        ll cur = -(1ll << 60);
        ll mx = -(1ll<<60);
        for (int i = 1; i <= n; i++) {
            cur = max(cur, mx);
            if(j) cur += a[i];
            else cur -= a[i];
            ans=max(ans, cur);
            mx=max(mx, dp[i][j]);
        }
    }
    cout << ans << "\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}