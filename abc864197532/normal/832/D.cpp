#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 100;

vector <int> adj[N];
int jump[N][logN], in[N], out[N], dep[N], _t;

void dfs(int v, int pa) {
    jump[v][0] = pa;
    in[v]= _t++;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
    out[v] = _t++;
}

void build(int n) {
    for (int i = 0; i < n; ++i) jump[i][0] = -1;
    _t = 0;
    dfs(0, -1);
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i < n; ++i) {
            int k = jump[i][j - 1];
            if (~k) jump[i][j] = jump[k][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (in[u] <= in[v] && out[u] >= out[v]) return u;
    if (in[v] <= in[u] && out[v] >= out[u]) return v;
    for (int i = logN - 1; i >= 0; --i) {
        int k = jump[u][i];
        if (~k && !(in[k] <= in[v] && out[k] >= out[v])) {
            u = k;
        }
    }
    return jump[u][0];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}

int solve(int a, int b, int c) {
    int k = lca(a, b), kk = lca(a, c);
    if (dep[k] < dep[kk]) swap(k, kk);
    int kkk = lca(b, c);
    if (dep[k] < dep[kkk]) swap(k, kkk);
    return max({dis(a, k), dis(b, k), dis(c, k)});
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, v;
    vector <int> a(3);
    cin >> n >> q;
    fop (i,1,n) {
        cin >> v; v--;
        adj[i].pb(v);
        adj[v].pb(i);
    }
    build(n);
    while (q--) {
        cin >> a[0] >> a[1] >> a[2];
        a[0]--, a[1]--, a[2]--;
        cout << solve(a[0], a[1], a[2]) + 1 << endl;
    }
}