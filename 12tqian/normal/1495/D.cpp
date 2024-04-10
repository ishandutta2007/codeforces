#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int P = 998244353;
const int INF = 1e9;

int add(int x, int y) { x += y; if (x >= P) x -= P; return x; }
int mult(int x, int y) { return 1LL * x * y % P; }
int madd(int& x, int y) { return x = add(x, y); }
int mmult(int& x, int y) { return x = mult(x, y); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vi> g(n);
    f0r(i, m) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<vi> d(n, vi(n, INF));
    vector<vi> ways(n, vi(n));
    f0r(i, n) d[i][i] = 0;
    f0r(i, n) each(j, g[i]) d[i][j] = 1;
    f0r(k, n) 
        f0r(i, n)
            f0r(j, n) 
                ckmin(d[i][j], d[i][k] + d[k][j]);

    vector<vi> cnt(n, vi(n));
    f0r(i, n) {
        vi verts(n);
        iota(all(verts), 0);
        sort(all(verts), [&](int x, int y) {
            return d[i][x] < d[i][y];
        });
        cnt[i][i] = 1;
        each(u, verts) {
            each(v, g[u]) {
                if (d[i][v] == d[i][u] + 1) {
                    madd(cnt[i][v], cnt[i][u]);
                }
            }
        }
    }
    f0r(v1, n) {
        f0r(v2, n) {
            int ans = 0;
            if (cnt[v1][v2] == 1) {
                ans = 1;
                f0r(i, n) {
                    if (d[v1][i] + d[i][v2] != d[v1][v2]) {
                        int num = 0;
                        each(j, g[i]) {
                            if (d[v1][j] + 1 == d[v1][i] && d[v2][j] + 1 == d[v2][i]) {
                                num++;
                            }
                        }
                        mmult(ans, num);
                    } 
                }
            } 
            cout << ans << " ";
        }
        cout << '\n';
    }

    return 0;
}

/** 
 * let's say a tree works, that means the rest of the edges all most between edges on the same level
 * let's say we precompute all the levels
 * two nodes, an edge can only work if it connects between adjacent levels
 * if you use n - 1 edges and everything is connected 
 * number of spanning trees on this new graph
 * there has to be exactly one shortest path between two vertices, otherwise it doesn't work
 * 
 */