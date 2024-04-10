#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;

int n;
ll f[maxn];

ll binpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y % 2 == 1) return binpow(x, y-1) * x % mod;
    return binpow(x * x % mod, y/2);
}

void solve() {
    cin >> n;
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i-1] * i % mod;
    }
    ll ans = n * f[n] % mod;
    for(int i=1; i < n; i++) {
        ans=(ans + mod - f[n]*binpow(f[i], mod-2) % mod) % mod;
    }
    cout << ans << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}