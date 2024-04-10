#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , v[MAXN] , u[MAXN] , H[MAXN] , ans[MAXN] , par[LOG][MAXN];
vector<ll> adj[MAXN];

void DFS(ll v , ll p = 0){
    H[v] = H[p] + 1;
    par[0][v] = p;
    for(ll u : adj[v]){
        if(u != p)  DFS(u , v);
    }
}

ll getPar(ll v , ll h){
    for(ll i = 0 ; i < LOG ; i++){
        if(h & (1ll << i))  v = par[i][v];
    }
    return v;
}

ll LCA(ll v , ll u){
    if(H[v] > H[u]) swap(v , u);
    u = getPar(u , H[u] - H[v]);
    if(u == v)  return v;
    for(ll i = LOG - 1 ; i >= 0 ; i--){
        if(par[i][v] != par[i][u]){
            v = par[i][v];
            u = par[i][u];
        }
    }
    return par[0][v];
}

void DFS2(ll v , ll p = 0){
    for(ll u : adj[v]){
        if(u != p)  DFS2(u , v) , ans[v] += ans[u];
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 1 ; i < n ; i++){
        cin >> v[i] >> u[i];
        adj[v[i]].push_back(u[i]);
        adj[u[i]].push_back(v[i]);
    }
    DFS(1);
    for(ll j = 1 ; j < LOG ; j++){
        for(ll i = 1 ; i <= n ; i++)    par[j][i] = par[j - 1][par[j - 1][i]];
    }

    cin >> q;
    while(q--){
        ll v , u;
        cin >> v >> u;
        ans[v]++;
        ans[u]++;
        ans[LCA(v , u)] -= 2;
    }
    DFS2(1);
    for(ll i = 1 ; i < n ; i++){
        if(H[v[i]] > H[u[i]])   cout << ans[v[i]] << sep;
        else    cout << ans[u[i]] << sep;
    }

    return 0;
}
/*

*/