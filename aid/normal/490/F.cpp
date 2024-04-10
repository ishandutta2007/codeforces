#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 6005;
int r[MAXN], dpup[MAXN], dpdown[MAXN], tin[MAXN], tout[MAXN], lca[MAXN][MAXN], n, t;
vector<int> g[MAXN], pr[MAXN];

void gett(int v, int p) {
    tin[v] = t++;
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p)
            gett(g[v][i], v);
    tout[v] = t++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

void getdp(int v, int p) {
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p)
            getdp(g[v][i], v);
    dpup[v] = 1;
    dpdown[v] = 1;
    for(int i = 0; i < n; i++)
        if(anc(v, i) && i != v) {
            if(r[i] < r[v])
                dpup[v] = max(dpup[v], dpup[i] + 1);
            else if(r[i] > r[v])
                dpdown[v] = max(dpdown[v], dpdown[i] + 1);
        }
}

void getlca(int v, int p) {
    pr[v].push_back(v);
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p) {
            getlca(g[v][i], v);
            for(size_t j = 0; j < pr[v].size(); j++)
                for(size_t k = 0; k < pr[g[v][i]].size(); k++)
                    lca[pr[v][j]][pr[g[v][i]][k]] = lca[pr[g[v][i]][k]][pr[v][j]] = v;
            for(size_t k = 0; k < pr[g[v][i]].size(); k++)
                pr[v].push_back(pr[g[v][i]][k]);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> r[i];
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    gett(0, -1);
    getdp(0, -1);
    getlca(0, -1);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, max(dpup[i], dpdown[i]));
        for(int j = i + 1; j < n; j++)
            if(!anc(i, j) && !anc(j, i)) {
                if(r[i] < r[j])
                    ans = max(ans, dpup[i] + dpdown[j] +
                              (int)(r[i] < r[lca[i][j]] && r[lca[i][j]] < r[j]));
                else if(r[i] > r[j])
                    ans = max(ans, dpup[j] + dpdown[i] +
                              (int)(r[j] < r[lca[i][j]] && r[lca[i][j]] < r[i]));
            }
    }
    cout << ans << '\n';
    return 0;
}