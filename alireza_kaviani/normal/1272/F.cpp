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

const ll MAXN = 210;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, dist[MAXN][MAXN][MAXN];
pair<int, pair<int, int>> prv[MAXN][MAXN][MAXN];
vector<int> adj[MAXN];
string s, t, A = "()";

ll ind(ll x, ll y, ll z) {
    return x * 210 * 210 + y * 210 + z;
}

void BFS() {
    for (ll i = 0; i < MAXN; i++) {
        for (ll j = 0; j < MAXN; j++) {
            for (ll k = 0; k < MAXN; k++) dist[i][j][k] = INF;
        }
    }

    queue<ll> q;
    dist[0][0][0] = 0;
    q.push(0);
    q.push(0);
    q.push(0);

    while (!q.empty()) {
        ll i = q.front();
        q.pop();
        ll j = q.front();
        q.pop();
        ll k = q.front();
        q.pop();

        for (ll l = 0; l < 2; l++) {
            ll x = j + (s[j] == A[l]), y = k + (t[k] == A[l]);
            ll z = i + ((A[l] == '(') ? 1 : -1);
            if (z < 0 || z >= MAXN) continue;
            if (dist[z][x][y] == INF) {
                dist[z][x][y] = dist[i][j][k] + 1;
                prv[z][x][y] = {i, {j, k}};
                q.push(z);
                q.push(x);
                q.push(y);
            }
        }
    }
}

int main() {
    fast_io;

    cin >> s >> t;
    n = s.size();
    m = t.size();

    s += ".";
    t += ".";

    BFS();

    ll x = 0, y = n, z = m;
    string ans;
    while (x + y + z > 0) {
        ans.push_back((prv[x][y][z].X < x ? '(' : ')'));
        ll nx = prv[x][y][z].X, ny = prv[x][y][z].Y.X, nz = prv[x][y][z].Y.Y;
        x = nx;
        y = ny;
        z = nz;
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
/*

*/