#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 405, INF = 1000 * 1000 * 1000 + 5;
int d[MAXN][MAXN][2];
char g[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = false;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v][u] = true;
        g[u][v] = true;
    }
    g[n - 1][n - 1] = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < 2; k++)
                d[i][j][k] = INF;
    queue< pair<pair<int, int>, int> > q;
    d[0][0][0] = 0;
    q.push(make_pair(make_pair(0, 0), 0));
    while(!q.empty()) {
        int v = q.front().first.first, u = q.front().first.second,
            t = q.front().second;
        q.pop();
        if(t == 0) {
            for(int i = 0; i < n; i++)
                if(g[v][i] && d[i][u][!t] == INF) {
                    d[i][u][!t] = d[v][u][t] + 1;
                    q.push(make_pair(make_pair(i, u), !t));
                }
        }
        else {
            for(int i = 0; i < n; i++)
                if(!g[u][i] && (i == n - 1 || i != v) && d[v][i][!t] == INF) {
                    d[v][i][!t] = d[v][u][t] + 1;
                    q.push(make_pair(make_pair(v, i), !t));
                }
        }
    }
    if(d[n - 1][n - 1][0] == INF)
        cout << -1 << '\n';
    else
        cout << d[n - 1][n - 1][0] / 2 << '\n';
    return 0;
}