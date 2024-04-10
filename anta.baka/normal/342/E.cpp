#include <bits/stdc++.h>
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using namespace std;
const int maxn = 1e5, INF = 1e9;

int n, q, dep[maxn], lg[2 * maxn + 1], bou[maxn], szeu;
vector<int> g[maxn];
vector<int> eu;
pair<int, int> t[2 * maxn][18];

void dfs(int v, int p) {
    bou[v] = sz(eu);
    eu.push_back(v);
    for(int to : g[v]) if(to != p) {
        dep[to] = dep[v] + 1;
        dfs(to, v);
        eu.push_back(v);
    }
}

int lca(int u, int v) {
    int l = bou[u], r = bou[v];
    if(l > r) swap(l, r);
    int x = lg[r - l + 1];
    return min(t[l][x], t[r - (1 << x) + 1][x]).second;
}

int dist(int u, int v) {
    int w = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[w];
}

int anc[maxn], ban[maxn], tsz[maxn];

void calc_sz(int v, int p) {
    tsz[v] = 1;
    for(int to : g[v]) if(to != p && !ban[to]) {
        calc_sz(to, v); tsz[v] += tsz[to];
    }
}

int get_c(int v, int p, int n) {
    for(int to : g[v]) if(to != p && !ban[to] && 2 * tsz[to] >= n) return get_c(to, v, n);
    return v;
}

void solve(int v, int p) {
    calc_sz(v, -1);
    int n = tsz[v];
    v = get_c(v, -1, n);
    ban[v] = 1;
    anc[v] = p;
    for(int to : g[v]) if(!ban[to]) solve(to, v);
}

vector<int> vec(maxn, INF);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    eu.reserve(2 * n);
    dfs(0, -1);
    szeu = sz(eu);
    for(int i = 2; i <= szeu; i++) lg[i] = lg[i >> 1] + 1;
    for(int i = 0; i < szeu; i++) t[i][0] = {dep[eu[i]], eu[i]};
    for(int j = 1; j < 18; j++)
        for(int i = 0; i + (1 << j) - 1 < szeu; i++)
            t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
    solve(0, -1);
    int v = 0;
    while(v != -1) vec[v] = dist(v, 0), v = anc[v];
    while(q--) {
        int type, v; cin >> type >> v; v--;
        if(type == 1) {
            int u = v;
            while(u != -1) vec[u] = min(vec[u], dist(u, v)), u = anc[u];
        } else {
            int ans = INF, u = v;
            while(u != -1) ans = min(ans, dist(v, u) + vec[u]), u = anc[u];
            cout << ans << '\n';
        }
    }
}