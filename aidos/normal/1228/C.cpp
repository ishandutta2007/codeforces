#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
ll x, y;
ll binpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y&1) return binpow(x, y-1) * x % mod;
    return binpow(x * x % mod, y/2);
}
ll calc(ll y, ll x) {
    if(y == 0) return 1;
    return binpow(x, y/x) * calc(y/x, x) % mod;
}
void solve() {
    cin >> x >> y;
    ll ans = 1;
    for(int i = 2; i < maxn; i++) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            ans = ans * calc(y, i) % mod;
        }
    }
    if(x > 1) ans = ans * calc(y, x) % mod;
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


#pragma clang diagnostic pop