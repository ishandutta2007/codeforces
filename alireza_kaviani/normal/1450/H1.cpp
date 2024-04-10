#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll x , ll y){
    ll ans = 1;
    for( ; y ; y >>= 1 , x = x * x % MOD){
        if(y & 1){
            ans = ans * x % MOD;
        }
    }
    return ans;
}

ll n , q , cntw[2] , cntq[2] , pw2[MAXN] , ipw2[MAXN] , fact[MAXN] , inv[MAXN];
string s;

ll C(ll n , ll r){
    if(r < 0 || r > n)  return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

ll calc(){
    ll ans = 0;
    for(int i = -n ; i <= n ; i++){
        if(abs(i) % 2 == 1)  continue;
        ll cur = C(cntq[0] + cntq[1] , cntq[0] + i + cntw[0] - cntw[1]);
        ans = (ans + abs(i) / 2 * cur) % MOD;
    }
    return ans * ipw2[cntq[0] + cntq[1] - 1] % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[0] = pw2[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        fact[i] = fact[i - 1] * i % MOD;
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }
    inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
    ipw2[MAXN - 1] = poww(pw2[MAXN - 1] , MOD - 2);
    for(int i = MAXN - 2 ; i >= 0 ; i--){
        inv[i] = inv[i + 1] * (i + 1) % MOD;
        ipw2[i] = ipw2[i + 1] * 2 % MOD;
    }

    cin >> n >> q >> s;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'w'){
            cntw[i % 2]++;
        }
        if(s[i] == '?'){
            cntq[i % 2]++;
        }
    }
    cout << calc() << endl;

    return 0;
}
/*

*/