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

ll q , v = 1 , u = 1 , cnt = 1 , H[MAXN] , par[LOG][MAXN];

ll getPar(ll v , ll h){
    for(ll i = 0 ; i < LOG ; i++)   if(h & (1ll << i))  v = par[i][v];
    return v;
}

ll dist(ll v , ll u){
    ll S = H[v] + H[u];
    if(H[v] > H[u]) swap(u , v);
    u = getPar(u , H[u] - H[v]);
    if(v == u)  return S - 2 * H[v];
    for(ll i = LOG - 1 ; i >= 0 ; i--)  if(par[i][v] != par[i][u])  v = par[i][v] , u = par[i][u];
    return S - 2 * H[par[0][v]];
}

void insert(ll A){
    ll B = ++cnt; par[0][B] = A;
    H[B] = H[A] + 1;
    for(ll i = 1 ; i < LOG ; i++)   par[i][B] = par[i - 1][par[i - 1][B]];
    if(dist(v , B) > dist(u , v))   u = B;
    if(dist(u , B) > dist(u , v))   v = B;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    insert(1) ; insert(1) ; insert(1);
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        insert(x) ; insert(x);
        cout << dist(v , u) << endl;
    }

    return 0;
}
/*

*/