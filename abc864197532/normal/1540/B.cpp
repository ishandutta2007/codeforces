#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 205;

vector <int> adj[N];
int in[N], out[N], _t, dep[N], jump[N][9];

void dfs (int v, int pa) {
    if (pa == -1) _t = 0;
    in[v] = _t++;
    jump[v][0] = pa;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
    out[v] = _t++;
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

long long modpow(long long a, int b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

long long dp[N][N];
bool vis[N][N];

int lca(int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int i = 8; i >= 0; --i) {
        int k = jump[u][i];
        if (~k && !anc(k, v)) {
            u = k;
        }
    }
    return jump[u][0];
}

long long get(int a, int b) {
    if (vis[a][b]) return dp[a][b];
    if (a == 0) return 1;
    if (b == 0) return 0;
    vis[a][b] = true;
    return dp[a][b] = (get(a - 1, b) + get(a, b - 1)) * ((mod + 1) / 2) % mod;
}

void solve() {
    int n;
    cin >> n;
    vector <vector <int>> dis(n, vector <int>(n, 1e8));
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dis[u][v] = dis[v][u] = 1;
    }
    for (int i = 0; i < n; ++i) dis[i][i] = 0;
    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        dfs(i, -1);
        for (int j = 1; j < 9; ++j) for (int k = 0; k < n; ++k) {
            int tmp = jump[k][j - 1];
            if (tmp != -1) jump[k][j] = jump[tmp][j - 1];
            else jump[k][j] = -1;
        }
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (anc(k, j)) ans++;
                else if (anc(j, k)) continue;
                else {
                    int l = lca(j, k);
                    ans += get(dis[l][k], dis[l][j]);
                }
                if (ans >= mod) ans -= mod;
            }
        }
    }
    cout << ans * modpow(n, mod - 2) % mod << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}