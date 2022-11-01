#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 405, Inf = 0x3f3f3f3f;

bool G[NMAX][NMAX];
int dist[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x][y] = true;
        G[y][x] = true;
    }
    if (G[0][n - 1]) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                G[i][j] = !G[i][j];
    }

    queue<int> q;
    q.push(0);
    memset(dist, Inf, sizeof dist);
    dist[0] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
            if (G[node][i] && dist[i] == Inf) {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

    if (dist[n - 1] == Inf) cout << "-1\n";
    else cout << dist[n - 1] << '\n';
}