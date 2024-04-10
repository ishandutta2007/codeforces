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

const int INF = 1e9;
const int N = 505;
const int K = 25;

int h[N][N];
int v[N][N];

int ans[N][N];
int go[N][N];
int vis[N][N];
int dist[N][N][K]; 

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    f0r(i, n) {
        f0r(j, m - 1) {
            cin >> h[i][j];
        }
    }
    f0r(i, n - 1) {
        f0r(j, m) {
            cin >> v[i][j];
        }
    }
    if (k % 2 == 1) {
        f0r(i, n) {
            f0r(j, m) {
                cout << -1 << " ";
            }
            cout << '\n';
        }
        return 0;
    }
    auto valid = [&](int x, int y) -> bool {
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    auto get_min = [&](int x, int y) -> int {
        int ret = INF;
        if (valid(x, y + 1)) ckmin(ret, h[x][y]);
        if (valid(x + 1, y)) ckmin(ret, v[x][y]);
        if (valid(x - 1, y)) ckmin(ret, v[x - 1][y]);
        if (valid(x, y - 1)) ckmin(ret, h[x][y - 1]);
        return ret;
    };
    auto get_weight = [&](int x, int y, int d) -> int {
        if (d == 0) return v[x][y];
        if (d == 1) return v[x - 1][y];
        if (d == 2) return h[x][y];
        if (d == 3) return h[x][y - 1];
        return -1;
    };
    f0r(i, N) f0r(j, N) f1r(it, 1, K) dist[i][j][it] = INF;
    f1r(it, 1, k / 2 + 1) {
        f0r(i, n) {
            f0r(j, m) {
                f0r(d, 4) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (!valid(ni, nj)) continue;
                    int w = get_weight(i, j, d);
                    ckmin(dist[i][j][it], dist[ni][nj][it - 1] + 2 * w);
                }
            }
        }
    }
    f0r(i, n) {
        f0r(j, m) {
            cout << dist[i][j][k / 2] << " ";
        }
        cout << '\n';
    }
    return 0;
}

/** 
 * call the minimum edge the ending edge, you get to that point, and you go back and forth
 * there is an ending vertex, from each edge you 
 */