#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll poww(ll x , ll y){
    ll ans = 1;
    for(; y ; y >>=1 , x = x * x % MOD){
        if(y & 1){
            ans = ans * x % MOD;
        }
    }
    return ans;
}

ll f , w , h , ans , tot , fact[MAXN] , inv[MAXN] , cnt[MAXN] , all[MAXN];

ll C(ll n , ll r){
    if(r == -1 && n == -1)  return 1;
    if(r < 0 || r > n)  return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
    for(int i = MAXN - 2 ; i >= 0 ; i--){
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }

    cin >> f >> w >> h;

    for(int i = 0 ; i < MAXN ; i++){
        all[i] = C(w - 1 , i - 1);
        cnt[i] = C(w - h * i - 1 , i - 1);
    }

    for(int i = 0 ; i + 1 < MAXN ; i++){
        ll cur = C(f - 1 , i - 1);
        ans = (ans + cur * (cnt[i - 1] + cnt[i] * 2 + cnt[i + 1])) % MOD;
        tot = (tot + cur * (all[i - 1] + all[i] * 2 + all[i + 1])) % MOD;
    }

    cout << ans * poww(tot , MOD - 2) % MOD << endl;

    return 0;
}
/*

*/