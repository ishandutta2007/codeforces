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

const int N = 605;
const ll INF = 1e18;

ll d[N][N];
ll mn[N][N]; // minimum if we con

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    
    f0r(i, N) f0r(j, N) d[i][j] = INF, mn[i][j] =INF;
    
    f0r(i, n) d[i][i] = 0;
    
    vector<array<int, 3>> ed;
    
    f0r(i, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        ed.pb({u, v, w});
        d[u][v] = d[v][u] = w;
    }
    
    f0r(k, n) {
        f0r(i, n) {
            f0r(j, n) {
                ckmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    int q; cin >> q;
    
    vector<vpi> paths(n);
    
    f0r(i, q) {
        int u, v, l; cin >> u >> v >> l;
        u--, v--;
        paths[u].eb(v, l);
        paths[v].eb(u, l);
    }
    
    f0r(u, n) { // path conditioned to start at u
        each(path, paths[u]) {
            int v = path.f;
            int l = path.s;
            f0r(i, n) {
                ckmin(mn[u][i], d[i][v] - l);
            }
        }
    }
    int ans = 0;
    each(e, ed) {
        int x = e[0];
        int y = e[1];
        int w = e[2];
        f0r(u, n) {
            if (d[u][x] + w + mn[u][y] <= 0) {
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}