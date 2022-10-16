#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5, LOGN = 20, MAXK = 1000 * 1000 + 5,
    MOD = 1000 * 1000 * 1000 + 7;
int p[MAXN][LOGN], tin[MAXN], tout[MAXN], add[MAXN][2], p2[MAXK], t;
vector< pair<int, int> > g[MAXN];

void dfs(int v) {
    tin[v] = t++;
    for(int i = 1; i < LOGN; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i].first != p[v][0]) {
            p[g[v][i].first][0] = v;
            dfs(g[v][i].first);
        }
    tout[v] = t++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int getLca(int v, int u) {
    if(anc(v, u))
        return v;
    if(anc(u, v))
        return u;
    for(int i = LOGN - 1; i >= 0; i--)
        if(!anc(p[v][i], u))
            v = p[v][i];
    return p[v][0];
}

void addOnPath(int v, int u) {
    int lca = getLca(v, u);
    add[v][0]++;
    add[u][1]++;
    add[lca][0]--;
    add[lca][1]--;
}

int dfs0(int v) {
    int res = 0;
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i].first != p[v][0]) {
            res += dfs0(g[v][i].first);
            if(res >= MOD)
                res -= MOD;
            add[v][0] += add[g[v][i].first][0];
            add[v][1] += add[g[v][i].first][1];
        }
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i].first == p[v][0]) {
            if(g[v][i].second == 1)
                res += p2[add[v][1]] - 1;
            else if(g[v][i].second == -1)
                res += p2[add[v][0]] - 1;
            if(res >= MOD)
                res -= MOD;
        }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    p2[0] = 1;
    for(int i = 1; i < MAXK; i++)
        p2[i] = 2 * p2[i - 1] % MOD;
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        b--;
        if(x == 0) {
            g[a].push_back(make_pair(b, 0));
            g[b].push_back(make_pair(a, 0));
        }
        else {
            g[a].push_back(make_pair(b, 1));
            g[b].push_back(make_pair(a, -1));
        }
    }
    dfs(0);
    int k;
    cin >> k;
    int prev = 0;
    for(int i = 0; i < k; i++) {
        int v;
        cin >> v;
        v--;
        addOnPath(prev, v);
        prev = v;
    }
    cout << dfs0(0) << '\n';
    return 0;
}