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

ll add(ll a, ll b){
    return (a + b) % mod;
}

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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll x, n;
    cin >> x >> n;
    ll y;

    y = x;
    set <ll> s;

    for(ll i = 2; i * i <= y; i++)if(y % i == 0){
        s.insert(i);
        while(y % i == 0)y /= i;
    }

    if(y != 1)s.insert(y);

    ll ans = 1;

    for(auto p : s){
        ll Mult = p;
        while(n / Mult != 0){
            ans = mul(ans, bp(p, n / Mult));
            if(inf / Mult < p)break;
            Mult *= p;
        }
    }

    cout << ans << "\n";

    return 0;
}