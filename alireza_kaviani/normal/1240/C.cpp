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

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<pll> adj[MAXN];
ll q, n, k, dp[MAXN][2];

void DFS(ll v, ll p = -1) {
    vector<ll> vec;
    for (pll i : adj[v]) {
        ll u = i.X, w = i.Y;
        if (u == p) continue;
        DFS(u, v);
        dp[v][1] += dp[u][1];
        dp[v][0] += dp[u][1];
        vec.push_back(dp[u][0] + w - dp[u][1]);
    }
    sort(all(vec), greater<ll>());
    for (ll i = 0; i < min(SZ(vec), k); i++) {
        if (vec[i] < 0) continue;
        dp[v][1] += vec[i];
        if (i + 1 < k) dp[v][0] += vec[i];
    }
}

int main() {
    fast_io;

    cin >> q;
    while (q--) {
        cin >> n >> k;
        for (ll i = 0; i < n + 10; i++) adj[i] = {}, dp[i][0] = dp[i][1] = 0;
        for (ll i = 1; i < n; i++) {
            ll v, u, w;
            cin >> v >> u >> w;
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }

        DFS(1);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }

    return 0;
}
/*

*/