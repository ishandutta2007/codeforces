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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 8e15;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , cnt , dist[MAXN] , comp[MAXN] , ans[MAXN] , mark[MAXN];
vector<ll> adj[MAXN];

void DFS(ll v , ll c){
    mark[v] = 1;
    comp[v] = c;
    for(ll u : adj[v]){
        if(!mark[u])    DFS(u , c);
    }
}

void BFS(ll v){
    fill(dist , dist + MAXN , INF);
    queue<ll> q;
    q.push(v);
    dist[v] = 0;

    ll A = 1 , mx = 0;
    while(!q.empty()){
        ll v = q.front();
        mx = dist[v];
        q.pop();
        for(ll u : adj[v]){
            if(dist[u] == INF){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
            if(dist[u] == dist[v])   A = 0;
        }
    }
    if(A == 0)  return;
    ans[comp[v]] = max(ans[comp[v]] , mx);
}

int main() {
    fast_io;
    fill(ans , ans + MAXN , -INF);

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++){
        ll v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(ll i = 1 ; i <= n ; i++){
        if(!mark[i])    DFS(i , cnt++);
    }

    for(ll i = 1 ; i <= n ; i++)    BFS(i);

    ll res = 0;
    for(ll i = 0 ; i < cnt ; i++)   res += ans[i];
    if(res < 0) return cout << -1 << endl , 0;
    cout << res << endl;

    return 0;
}
/*

*/