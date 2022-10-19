#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , s , t , v[MAXN] , u[MAXN] , w[MAXN] , dist[2][MAXN] , mark[MAXN] , ans[MAXN] , bridge[MAXN] , H[MAXN] , mn[MAXN];
vector<pll> g[2][MAXN] , adj[MAXN];

void Dijkstra(ll ind , ll v){
    fill(mark , mark + MAXN , 0);
    fill(dist[ind] , dist[ind] + MAXN , INF);

    priority_queue<pll , vector<pll> , greater<pll>> pq;
    pq.push({dist[ind][v] = 0 , v});
    while(!pq.empty()){
        ll v = pq.top().Y; pq.pop();
        if(mark[v]) continue;
        mark[v] = 1;
        for(pll i : g[ind][v]){
            ll u = i.X , w = i.Y;
            if(dist[ind][u] > dist[ind][v] + w){
                dist[ind][u] = dist[ind][v] + w;
                pq.push({dist[ind][u] , u});
            }
        }
    }
}

void DFS(ll v , ll p = 0 , ll IND = -1){
    H[v] = H[p] + 1;
    mark[v] = 1;
    mn[v] = INF;
    for(pll i : adj[v]){
        ll u = i.X , ind = i.Y;
        if(!mark[u]){
            DFS(u , v , ind);
            mn[v] = min(mn[v] , mn[u]);
            if(mn[u] > H[v])    bridge[ind] = 1;
        }
        else if(IND != ind){
            mn[v] = min(mn[v] , H[u]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    for(ll i = 0 ; i < m ; i++){
        cin >> v[i] >> u[i] >> w[i];
        g[0][v[i]].push_back({u[i] , w[i]});
        g[1][u[i]].push_back({v[i] , w[i]});
    }

    Dijkstra(0 , s);
    Dijkstra(1 , t);

    for(ll i = 0 ; i < m ; i++){
        if(dist[0][v[i]] + w[i] + dist[1][u[i]] == dist[0][t]){
            adj[v[i]].push_back({u[i] , i});
            adj[u[i]].push_back({v[i] , i});
        }
        ans[i] = dist[0][t] - dist[0][v[i]] - dist[1][u[i]] - 1;
    }
    fill(mark , mark + MAXN , 0);
    DFS(s);

    for(ll i = 0 ; i < m ; i++){
        //cout << ans[i] << sep << bridge[i] << sep << mn[v[i]] << sep << mn[u[i]] << sep << H[v[i]] << sep << H[u[i]] << endl;
        if(bridge[i])    cout << "YES" << endl;
        else if(ans[i] > 0) cout << "CAN" << sep << w[i] - ans[i] << endl;
        else    cout << "NO" << endl;
    }

    return 0;
}