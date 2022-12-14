/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-01 18:46:01
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

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

ll n , m , mn , E[MAXN] , mark[MAXN];
vector<ll> adj[MAXN];
vector<pll> vec;

void DFS(ll v , ll p , ll h , ll root){
    E[root] = max(E[root] , h);
    for(ll u : adj[v])  if(u != p)  DFS(u , v , h + 1 , root);
}

void DFS2(ll v){
    if(E[v] < E[mn])    mn = v;
    mark[v] = 1;
    for(ll u : adj[v])  if(!mark[u])    DFS2(u);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(ll i = 1 ; i <= m ; i++){
        ll v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(ll i = 1 ; i <= n ; i++)    DFS(i , -1 , 0 , i);
    for(ll i = 1 ; i <= n ; i++)    if(!mark[i])    mn = i , DFS2(i) , vec.push_back({E[mn] , mn});

    ll ans = *max_element(E , E + MAXN);
    sort(all(vec) , greater<pll>());
    if(SZ(vec) == 2)    ans = max(ans , vec[0].X + vec[1].X + 1);
    if(SZ(vec) >= 3)    ans = max(ans , max(vec[0].X + vec[1].X + 1 , vec[1].X + vec[2].X + 2));
    
    cout << ans << endl;
    for(ll i = 1 ; i < SZ(vec) ; i++)   cout << vec[0].Y << sep << vec[i].Y << endl;

    return 0;
}
/*

*/