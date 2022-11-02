#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
ll n, m, k;
ll binpow(ll x, ll y) {
    ll res = 1;
    while(y > 0) {
        if(y % 2) {
            res = (res * x) % mod;
        }
        y /= 2;
        x = x*x % mod;
    }
    return res;
}
void solve() {
    cin >> n >> m >> k;
    if(k == -1) {
        if(n % 2 != m % 2) {
            cout << 0 << "\n";
            return;
        }
    }
    n--;
    m--;
    n %= mod-1;
    m %= mod-1;
    cout << binpow(2, n * m % (mod-1)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}