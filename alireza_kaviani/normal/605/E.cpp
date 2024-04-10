#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double , ll> pdd;

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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , mark[MAXN] , P[MAXN][MAXN];
double dist[MAXN] , val[MAXN] , p[MAXN];
vector<pll> adj[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++)   for(int j = 1 ; j <= n ; j++)   cin >> P[i][j];
    fill(dist , dist + MAXN , INF);
    fill(p , p + MAXN , 1);
    dist[n] = 0;
    for(int i = 0 ; i < n ; i++){
        //cout << pq.top().X << sep << pq.top().Y << endl;
        ll v = 0;
        for(int j = 1 ; j <= n ; j++)   if(!mark[j] && dist[j] < dist[v])   v = j;
        mark[v] = 1;
        for(int u = 1 ; u <= n ; u++){
            if(u == v)  continue;
            ll w = P[u][v];
            double P = double(w) / double(100);
            double V = val[u] + p[u] * P * (dist[v] + 1);
            double pu = p[u] * (1 - P);
            double D = (V + pu) / (1.0 - pu);
          //      cout << v << sep << u << sep << dist[u] << sep << p[u] << sep << val[u] << endl;
            if(D < dist[u]){
                dist[u] = D;
                val[u] = V;
                p[u] = pu;
            }
            
        }
    }
    printf("%.15f" , dist[1]);
    

    return 0;
}
/*

*/