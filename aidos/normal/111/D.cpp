#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, m, k;
ll f[maxn];
ll rf[maxn];
ll binpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y & 1) return binpow(x, y-1) * x % mod;
    return binpow(x * x % mod, y/2);
}
ll dp[1010][1010];
ll C(int n, int k) {
    if(n < k) return 0;
    return f[n] * rf[k] % mod * rf[n-k] % mod;
}
void solve() {
    cin >> m >> n >> k;
    f[0] = 1;
    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * i % mod;
    }
    rf[maxn - 1] = binpow(f[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--) {
        rf[i] = rf[i+1] * (i + 1) % mod;
    }
    if(n == 1) {
        cout << binpow(k, m) << "\n";
        return;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j] * j % mod + dp[i-1][j-1]) % mod;
        }
    }
    ll ans = 0;
    for(int j = 0; j <= m; j++) {
        ll A = binpow(j, (n-2) * m);
        for(int i = j; i <= m && i <= k; i++) {
            ll cur = dp[m][i] * dp[m][i] % mod;

            ll cnt = C(k, i) * C(i, j) % mod * C(k-i, i - j) % mod;
            cnt *= f[i];
            cnt %= mod;
            cnt *= f[i];
            cnt %= mod;
            ans = (ans + cur * cnt%mod * A) % mod;
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