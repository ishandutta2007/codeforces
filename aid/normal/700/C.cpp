#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1005, MAXM = 30 * 1000 + 5, INF = 2000 * 1000 * 1000 + 5;
char used[MAXN], del[MAXM], br[MAXM];
int w[MAXM], tin[MAXN], f[MAXN], tt;
vector< pair<int, int> > g[MAXN];

bool getPath(int v, int t, vector<int> &path) {
    used[v] = true;
    if(v == t)
        return true;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, id = g[v][i].second;
        if(used[u])
            continue;
        path.push_back(id);
        if(getPath(u, t, path))
            return true;
        path.pop_back();
    }
    return false;
}

void getBridges(int v, int p) {
    used[v] = true;
    tin[v] = tt++;
    f[v] = tin[v];
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, id = g[v][i].second;
        if(id == p || del[id])
            continue;
        if(used[u])
            f[v] = min(f[v], tin[u]);
        else {
            getBridges(u, id);
            f[v] = min(f[v], f[u]);
            if(f[u] > tin[v])
                br[id] = true;
        }
    }
}

int dfs(int v, int t, int x) {
    used[v] = true;
    if(v == t)
        return x;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, id = g[v][i].second;
        if(used[u] || del[id])
            continue;
        int y = x;
        if(br[id] && (y == -1 || w[id] < w[y]))
            y = id;
        int res = dfs(u, t, y);
        if(res != -2)
            return res;
    }
    return -2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u >> w[i];
        v--;
        u--;
        g[v].push_back(make_pair(u, i));
        g[u].push_back(make_pair(v, i));
    }
    vector<int> path;
    if(!getPath(s, t, path)) {
        cout << 0 << '\n' << 0 << '\n' << '\n';
        return 0;
    }
    int a = -1, b = -1, ans = INF;
    for(size_t i = 0; i < path.size(); i++) {
        int aa = path[i];
        del[aa] = true;
        for(int j = 0; j < n; j++)
            used[j] = false;
        for(int j = 0; j < m; j++)
            br[j] = false;
        tt = 0;
        for(int j = 0; j < n; j++)
            if(!used[j])
                getBridges(j, -1);
        for(int j = 0; j < n; j++)
            used[j] = false;
        int bb = dfs(s, t, -1);
        del[aa] = false;
        if(bb == -1)
            continue;
        if(bb == -2 && w[aa] < ans) {
            ans = w[aa];
            a = aa;
            b = -1;
        }
        if(bb >= 0 && w[aa] + w[bb] < ans) {
            ans = w[aa] + w[bb];
            a = aa;
            b = bb;
        }
    }
    if(ans == INF) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
    if(b == -1)
        cout << 1 << '\n' << a + 1 << '\n';
    else
        cout << 2 << '\n' << a + 1 << ' ' << b + 1 << '\n';
    return 0;
}