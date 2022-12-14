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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

ll a[MAXN], ans = 0;

const ll mod = 1e9 + 7;

ll gcd(ll a, ll b){
    while(a && b)if(a > b)a %= b;else b %= a;
    return a + b;
}

void dfs(ll x, vector <pll> c, ll deep, ll pr = 0){
    vector <pll> d;
    for(auto i : c){
        if(i.se == 0){
            d.p_b(i);
        }else{
            while(d.size() > 1 && d.back().fi == (gcd(i.fi, a[x])))d.pop_back();
            d.p_b({gcd(i.fi, a[x]), i.se});
        }
    }
    d.p_b({a[x], deep});
    c.clear();
    c = d;
    d.clear();
    ll N = c.size();
    for(int i = N - 1; i > 0; i--){
        //cout << c[i].fi << " " << (c[i].se - c[i - 1].se) << endl;
        ans += c[i].fi * (c[i].se - c[i - 1].se);
        ans %= mod;
    }

    for(auto to : v[x])if(to != pr)dfs(to, c, deep + 1, x);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    vector <pll> c;

    c.p_b({0ll, 0ll});

    dfs(1ll, c, 1ll);

    cout << ans << "\n";

    return 0;
}