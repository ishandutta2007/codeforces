/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

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

set_random;

const ll MAXN = 2e5 + 10;
const ll MAXK = 6;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN];
ll n , k , ans , v , u , sum[MAXN][MAXK] , cnt[MAXN][MAXK];

void add(ll v){
    ll c = cnt[v][k - 1] , s = sum[v][k - 1];
    for(ll i = k - 1 ; i >= 1 ; i--){
        cnt[v][i] = cnt[v][i - 1];
        sum[v][i] = sum[v][i - 1];
    }
    cnt[v][0] = c;
    sum[v][0] = s + c;
}

void DFS(ll v , ll p = -1){
    cnt[v][0] = 1;
    for(ll u : adj[v]){
        if(u == p)  continue;
        DFS(u , v);
        add(u);

        for(ll i = 0 ; i < k ; i++){
            for(ll j = 0 ; j < k ; j++){
                ans += sum[v][i] * cnt[u][j] + sum[u][j] * cnt[v][i] + (i + j + k - 1) / k * cnt[v][i] * cnt[u][j];
            }
        }
        for(ll i = 0 ; i < k ; i++){
            cnt[v][i] += cnt[u][i];
            sum[v][i] += sum[u][i];
        }
    }
}

int main() {
    fast_io;

    cin >> n >> k;
    for(ll i = 1 ; i < n ; i++){
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    DFS(1);
    cout << ans << endl;

    return 0;
}
/*

*/