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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , timer , st[MAXN] , H[MAXN] , fn[MAXN] , fen[2][MAXN];
vector<ll> adj[MAXN];

void DFS(ll v , ll p = 0){
    H[v] = H[p] + 1;
    st[v] = ++timer;
    for(ll u : adj[v])  if(u != p)  DFS(u , v);
    fn[v] = timer;
}

void update(ll ind , ll x , ll val){
    for( ; x < MAXN ; x += x & -x)  fen[ind][x] += val;
}

ll get(ll ind , ll x){
    ll ans = 0;
    for( ; x > 0 ; x -= x & -x) ans += fen[ind][x];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for(ll i = 1 ; i < n ; i++){
        ll v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);

    while(q--){
        ll t , v , val , d;
        cin >> t >> v;
        if(t == 0){
            cin >> val >> d;
            ll x = d - H[v] + 2;
            if(x >= 1){
                update(1 , 1 , val);
                update(1 , x + 1 , -val);
                update(0 , min(fn[v] + 1 , max(st[v] - d , x + st[v] - H[v] + 1)) , val);
                update(0 , min(fn[v] , st[v] + d) + 1 , -val);
            }
            else{
                update(0 , st[v] - d , val);
                update(0 , min(fn[v] , st[v] + d) + 1 , -val);
            }
        }
        if(t == 1){
            cout << get(0 , st[v]) + get(1 , H[v]) << endl;
        }
    }

    return 0;
}
/*

*/