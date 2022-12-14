#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
const ll N = 1500;
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll fact[MAXN];

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll bp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n & 1)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

ll _div(ll a, ll b){
    return mul(a, bp(b, mod - 2));
}

ll c(ll n, ll k){
    if(!k)return 1;
    if(k > n)return 0;
    return _div(fact[n], mul(fact[n - k], fact[k]));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)fact[i] = mul(fact[i - 1], i);

    ll ans = 0;
    ll n, m;
    cin >> n >> m;

    if(n > 2){
        for(int i = 1; i <= m; i++){
            (ans += mul(bp(2, n - 3), c(m - 1, n - 2))) %= mod;
            ans -= mul(bp(2, n - 3), c(i - 1, n - 2));
            while(ans < 0)ans += mod;
        }
    }

    cout << ans << "\n";

    return 0;
}