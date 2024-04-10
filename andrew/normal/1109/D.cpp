#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll fact[MAXN];

ll bp(ll a, ll n){
    ll res = 1;
    if(n == -1)return bp(a, mod - 2);
    while(n){
        if(n & 1)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll divMod(ll a, ll b){
    return mul(a, bp(b, mod - 2));
}

ll c(ll n, ll k){
    return divMod(fact[n], mul(fact[k], fact[n - k]));
}

ll f(ll x, ll y){
    return mul(y, bp(x, x - y - 1));
}

ll A(ll n, ll k){
    if(n < k)return 0;
    return mul(fact[k], c(n, k));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    fact[0] = fact[1] = 1;

    for(ll i = 2; i <= 1e6; i++)fact[i] = mul(fact[i - 1], i);

    ll ans = 0;


    for(int i = 1; i < n; i++){
        if(i > m)continue;
        (ans += mul(A(n - 2, i - 1), mul(c(m - 1, i - 1), mul(bp(m, n - i - 1), f(n, i + 1))))) %= mod;
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}