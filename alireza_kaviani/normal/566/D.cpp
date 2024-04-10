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
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , par[MAXN] , nxt[MAXN] , sz[MAXN];
set<ll> st;

ll Find(ll v){
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v , ll u){
    v = Find(v);
    u = Find(u);
    if(u == v)  return;
    if(sz[v] < sz[u])   swap(v , u);
    par[u] = v;
    sz[v] += sz[u];
}

int main() {
    fast_io;
    fill(par , par + MAXN , -1);
    fill(sz , sz + MAXN , 1);

    cin >> n >> q;
    for(ll i = 1 ; i <= n ; i++)    st.insert(i);
    while(q--){
        ll t , x , y;
        cin >> t >> x >> y;
        if(t == 1)  Union(x , y);
        if(t == 2){
            vector<ll> vec;
            auto it = st.lower_bound(x);
            for( ; (*it) < y ; it++){
                ll A = *it;
                Union(A , A + 1);
                vec.push_back(A);
            }
            for(ll i : vec)   st.erase(i);
        }
        if(t == 3)  cout << (Find(x) == Find(y) ? "YES" : "NO") << endl;
    }

    return 0;
}
/*

*/