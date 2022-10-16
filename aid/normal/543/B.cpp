#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 3005, INF = 1000 * 1000 * 1000 + 5;
int d[MAXN][MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int s0, t0, l0, s1, t1, l1;
    cin >> s0 >> t0 >> l0 >> s1 >> t1 >> l1;
    s0--;
    t0--;
    s1--;
    t1--;
    for(int s = 0; s < n; s++) {
        for(int j = 0; j < n; j++)
            d[s][j] = INF;
        d[s][s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(size_t i = 0; i < g[v].size(); i++)
                if(d[s][g[v][i]] > d[s][v] + 1) {
                    d[s][g[v][i]] = d[s][v] + 1;
                    q.push(g[v][i]);
                }
        }
    }
    if(d[s0][t0] > l0 || d[s1][t1] > l1) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = d[s0][t0] + d[s1][t1];
    for(int v = 0; v < n; v++)
        for(int u = 0; u < n; u++)
            if(d[s0][v] + d[v][u] + d[u][t0] <= l0) {
                if(d[s1][v] + d[v][u] + d[u][t1] <= l1)
                    ans = min(ans, d[s0][v] + d[v][u] + d[u][t0] +
                              d[s1][v] + d[u][t1]);
                if(d[s1][u] + d[u][v] + d[v][t1] <= l1)
                    ans = min(ans, d[s0][v] + d[v][u] + d[u][t0] +
                              d[s1][u] + d[v][t1]);
            }
    cout << m - ans << '\n';
    return 0;
}