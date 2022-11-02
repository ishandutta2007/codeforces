#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = 998244353;
int n, m;
int a[maxn];
int dp[maxn];
ll d[maxn];
ll s[maxn];
ll binpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y % 2 == 0) return binpow(x * x % mod, y/2);
    return binpow(x, y-1) * x % mod;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + d[i];
    }
    for(int i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        int pos = lower_bound(d+1,d + n + 1, y) - d;
        ll A = n + 1 - pos;
        if(A < x) {
            cout << 0 << "\n";
            continue;
        }
        ll tt = (A + 1- x) * binpow(A+1, mod-2) % mod * (s[pos-1] % mod) % mod;
        tt = (tt+(A - x) * binpow(A, mod-2) % mod * ((s[n] - s[pos-1]) % mod))% mod;
        cout << tt << "\n";

    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}