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
//#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , d[MAXN] , mark[MAXN];
vector<ll> adj[MAXN];
set<pll> st;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 1 ; i < n ; i++){
        ll v , u;
        cin >> v >> u;
        d[v]++;
        d[u]++;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(ll i = 1 ; i <= n ; i++)    st.insert({d[i] , i});

    while(!st.empty()){
        if(st.size() == 1){
            ll ans = (*st.begin()).Y;
            cout << "! " << ans << endl;
            return 0;
        }
        ll v = (*st.begin()).Y; st.erase(st.begin());
        ll u = (*st.begin()).Y; st.erase(st.begin());
        mark[v] = mark[u] = 1;
        cout << "? " << v << sep << u << endl;
        ll x;
        cin >> x;
        if(x == v || x == u){
            cout << "! " << x << endl;
            return 0;
        }
        for(ll i : adj[v]){
            if(mark[i]) continue;
            st.erase({d[i] , i});
            d[i]--;
            st.insert({d[i] , i});
        }
        for(ll i : adj[u]){
            if(mark[i]) continue;
            st.erase({d[i] , i});
            d[i]--;
            st.insert({d[i] , i});
        }
    }

    return 0;
}
/*

*/