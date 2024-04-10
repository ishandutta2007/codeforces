#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
ll fact[maxn];
ll binpow(ll x, ll y) {
    ll res = 1;
    while(y > 0) {
        if(y % 2) res= res * x % mod;
        x = x*x % mod;
        y/=2;
    }
    return res;
}
void solve(){
    cin >> n;

    fact[0] = 1;

    for(int i = 1; i < maxn; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    ll ans = fact[n * 2 - 1] * binpow(fact[n - 1] * fact[n] % mod, mod-2) % mod;
    ans = ans * 2 % mod;
    ans = (ans - n) % mod;
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}