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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
const ll mod = 998244353;
const ll MOD = mod * (mod - 2);
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll bp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n & 1)res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}


ll Div(ll a, ll b){
    return mul(a, bp(b, mod - 2));
}

void main_solve(){
    ll n;
    cin >> n;
    map <ll, ll> mp;
    vector <vector <ll>> a(n);
    for(int i = 0; i < n; i++){
        ll k;
        cin >> k;
        a[i].resize(k);
        for(auto &j : a[i])cin >> j;
        for(auto j : a[i])mp[j]++;
    }

    ll ans = 0;
    ll shans = sqr(Div(1, n)) % mod;
    for(int i = 0; i < n; i++){
        ll kek = mul(shans, Div(1, sz(a[i])));
        for(auto j : a[i]){
            ans += kek * mp[j];
            if(ans >= MOD)ans -= MOD;
        }
        ans %= mod;
    }

    cout << ans << "\n";

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL

    return 0;
}