#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll sum(ll a, ll b){
    return (a + b) % MOD;
}

ll fact[MAXN];

ll f(ll x){
    return fact[x];
}

ll divMOD(ll a, ll b){
    return mul(a, bp(b, mod - 2));
}

ll C(ll n, ll k){
    return divMOD(f(n), mul(f(k), f(n - k)));
}

void solve(){
    int n, k;
    cin >> n >> k;
    if(n % 2 == 1){
        ll s = 1;
        for(int j = 0; j < n; j += 2) {
            s = (s + C(n, j)) % mod;
        }
        cout << bp(s, k) << "\n";
    }else{
        ll ans = 0, s = 0;
        for(int j = 0; j < n; j += 2) {
            s = (s + C(n, j)) % mod;
        }
        ans = bp(s, k);
        for(int i = 0; i < k; i++){
            ans = sum(ans, mul(bp(s, i), bp(bp(2, n), k - i - 1)));
        }
        cout << ans << "\n";
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;

    for(int i = 1; i < MAXN; i++){
        fact[i] = mul(fact[i - 1], i);
    }

    int t;
    cin >> t;
    //t = 1;

    while(t--){
        solve();
    }

    return 0;
}