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

ll q, n, m;
set<ll> indSet;
set<pll> adj[MAXN];

void erase(ll v) {
    indSet.erase(v);
    for (auto &i : adj[v]) {
        ll u = i.X, id = i.Y;
        adj[u].erase({v, id});
    }
    adj[v].clear();
}

int main() {
    fast_io;

    cin >> q;
    while (q--) {
        cin >> n >> m;
        n *= 3;
        fill(adj, adj + n + 10, set<pll>());

        vector<ll> matching;
        for (ll i = 1; i <= m; i++) {
            ll v, u;
            cin >> v >> u;
            adj[v].insert({u, i});
            adj[u].insert({v, i});
        }

        for (ll i = 1; i <= n; i++) indSet.insert(i);

        for (ll i = 1; i <= n; i++) {
            if (adj[i].size() == 0) continue;
            ll v = (*adj[i].begin()).X, id = (*adj[i].begin()).Y;
            matching.push_back(id);
            erase(i);
            erase(v);
        }

        if (matching.size() >= n / 3) {
            cout << "Matching" << endl;
            for (ll i = 0; i < n / 3; i++) cout << matching[i] << sep;
            cout << endl;
        } else {
            cout << "IndSet" << endl;
            ll t = 0;
            for (auto &i : indSet) {
                if (t >= n / 3) break;
                cout << i << sep;
                t++;
            }
            cout << endl;
        }

        indSet.clear();
    }

    return 0;
}
/*

*/