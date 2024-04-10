#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;

int n, m;
ll f[maxn];

ll binpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y % 2 == 1) return binpow(x, y-1) * x % mod;
    return binpow(x * x % mod, y/2);
}

void solve() {
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1; i <= m; i++) {
        f[i] = f[i-1] * i % mod;
    }
    ll cnt = 0;
    for(int i = 1; i < n-1; i++) {
        cnt = (binpow(2, i-1) * binpow(2, n - 2 - i) % mod + cnt) % mod;
    }

    //cout << cnt << "\n";
    cout << cnt * f[m] % mod * binpow(f[n-1] * f[m-n+1] % mod, mod-2) % mod << "\n";
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