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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, inDeg[MAXN], outDeg[MAXN];

int main() {
    fast_io;

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        inDeg[v] += w;
        outDeg[u] += w;
    }

    for (ll i = 1; i <= n; i++) {
        if (inDeg[i] > outDeg[i]) {
            inDeg[i] -= outDeg[i];
            outDeg[i] = 0;
        } else {
            outDeg[i] -= inDeg[i];
            inDeg[i] = 0;
        }
    }

    ll ind = 1;
    vector<pair<pll, ll>> E;
    for (ll i = 1; i <= n; i++) {
        while (inDeg[i] != 0) {
            ll t = min(inDeg[i], outDeg[ind]);
            if (t) E.push_back({{i, ind}, t});
            inDeg[i] -= t;
            outDeg[ind] -= t;
            if (outDeg[ind] == 0) ind++;
        }
    }

    cout << E.size() << endl;
    for (pair<pll, ll> i : E) {
        cout << i.X.X << sep << i.X.Y << sep << i.Y << endl;
    }

    return 0;
}
/*

*/