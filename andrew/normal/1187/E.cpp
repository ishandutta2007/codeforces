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
mt19937_64 gen;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

ll kol[MAXN], su[MAXN];

void dfs(ll x, ll pr){
    kol[x] = 1;
    for(auto to : v[x])if(to != pr){
        dfs(to, x);
        kol[x] += kol[to];
        su[x] += su[to];
    }
    su[x] += kol[x];
}

ll ans = -1e18, n;

void go(ll x, ll pr, ll S = 0){
    ans = max(ans, S + su[x] - kol[x] + n);
    ll sc = 0, MS = 0;
    for(auto to : v[x])if(to != pr){
        sc += su[to];
    }

    for(auto to : v[x])if(to != pr){
        MS = sc + S - su[to] + n - kol[to];
        go(to, x, MS);
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1ll, 0ll);
    go(1ll, 0ll, 0ll);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}