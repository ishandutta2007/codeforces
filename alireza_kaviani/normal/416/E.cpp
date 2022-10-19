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

const ll MAXN = 500 + 10;
const ll MAXM = 1e6 + 10;
const ll LOG = 22;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , v[MAXM] , u[MAXM] , w[MAXM] , dist[MAXN][MAXN] , inDeg[MAXN] , ans[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(ll i = 0 ; i < MAXN ; i++){
        for(ll j = 0 ; j < MAXN ; j++){
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    cin >> n >> m;

    for(ll i = 0 ; i < m ; i++){
        cin >> v[i] >> u[i] >> w[i];
        dist[v[i]][u[i]] = dist[u[i]][v[i]] = w[i];
    }

    for(ll k = 1 ; k <= n ; k++){
        for(ll i = 1 ; i <= n ; i++){
            for(ll j = 1 ; j <= n ; j++){
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }


    for(ll i = 1 ; i <= n ; i++){
        fill(inDeg , inDeg + MAXN , 0);
        for(ll j = 0 ; j < m ; j++){
            if(dist[i][v[j]] > dist[i][u[j]]) swap(v[j] , u[j]);
            if(dist[i][u[j]] == dist[i][v[j]] + w[j])   inDeg[u[j]]++;
        }
        for(ll j = 1 ; j <= n ; j++){
            for(ll k = 1 ; k <= n ; k++){
                if(dist[i][k] + dist[k][j] == dist[i][j]){
                    ans[i][j] += inDeg[k];
                }
            }
        }
    }

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = i + 1 ; j <= n ; j++)    cout << ans[i][j] << sep;
    }

    return 0;
}
/*

*/