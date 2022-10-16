#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 300 * 1000 + 5, LOGN = 22;
int ts[MAXN], d[MAXN][LOGN];
vector<int> g[MAXN];

void dfs(int v) {
    ts[v] = 1;
    d[v][0] = MAXN - 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        dfs(u);
        ts[v] += ts[u];
        if(ts[u] > ts[d[v][0]])
            d[v][0] = u;
    }
    for(int i = 1; i < LOGN; i++)
        d[v][i] = d[d[v][i - 1]][i - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    for(int i = 0; i < LOGN; i++)
        d[MAXN - 1][i] = MAXN - 1;
    dfs(0);
    for(int qq = 0; qq < q; qq++) {
        int v;
        cin >> v;
        v--;
        int sz = ts[v];
        for(int i = LOGN - 1; i >= 0; i--)
            if(2 * ts[d[v][i]] > sz)
                v = d[v][i];
        cout << v + 1 << '\n';
    }
    return 0;
}