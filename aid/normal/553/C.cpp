#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
char used[MAXN], col[MAXN];
int comp[MAXN];
vector<int> g[MAXN], badg[MAXN], gc[MAXN];

void dfs(int v, int col) {
    comp[v] = col;
    for(size_t i = 0; i < g[v].size(); i++)
        if(comp[g[v][i]] == -1)
            dfs(g[v][i], col);
}

bool dfs0(int v) {
    used[v] = true;
    for(size_t i = 0; i < gc[v].size(); i++) {
        if(used[gc[v][i]]) {
            if(col[gc[v][i]] == col[v])
                return true;
        }
        else {
            col[gc[v][i]] = !col[v];
            if(dfs0(gc[v][i]))
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--;
        u--;
        if(c) {
            g[v].push_back(u);
            g[u].push_back(v);
        }
        else {
            badg[v].push_back(u);
            badg[u].push_back(v);
        }
    }
    for(int i = 0; i < n; i++)
        comp[i] = -1;
    int k = 0;
    for(int i = 0; i < n; i++)
        if(comp[i] == -1)
            dfs(i, k++);
    for(int v = 0; v < n; v++)
        for(size_t i = 0; i < badg[v].size(); i++) {
            int u = badg[v][i];
            if(comp[v] == comp[u]) {
                cout << 0 << '\n';
                return 0;
            }
            gc[comp[v]].push_back(comp[u]);
        }
    int ans = 1;
    bool b = false;
    for(int i = 0; i < k; i++)
        if(!used[i]) {
            if(dfs0(i)) {
                cout << 0 << '\n';
                return 0;
            }
            if(b)
                ans = (2 * ans) % MOD;
            else
                b = true;
        }
    cout << ans << '\n';
    return 0;
}