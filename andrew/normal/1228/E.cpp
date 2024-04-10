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
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll fact[MAXN];

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll add(ll a, ll b){
    return (a + b) % mod;
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

ll c(ll n, ll k){
    return mul(fact[n], bp(mul(fact[k], fact[n - k]), mod - 2));
}

ll n;

ll kol(ll i, ll j){
    return i * n + j * n - i * j;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;

    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)fact[i] = mul(fact[i - 1], i);

    ll ans = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            ll q = 1;
            if((i + j) % 2)q = -1;
            ans += q * mul(mul(c(n, i), c(n, j)), mul(bp(k - 1, kol(i, j)), bp(k, sqr(n) - kol(i, j))));

            while(ans < 0)ans += mod;
            ans %= mod;
        }
    }

    cout << ans << "\n";

    return 0;
}