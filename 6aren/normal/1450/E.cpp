#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 205;

int n, m;

ii range[N];
bool enEdge[N][N];
vector<int> g[N];
bool used[N];
bool col[N];

void dfs(int u, int c) {
    used[u] = 1;
    col[u] = c;
    for (int e : g[u]) {
        if (!used[e]) dfs(e, 1 - c);
    }
}

int res[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        if (t == 1) enEdge[u][v] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        for (int e : g[i]) if (col[i] == col[e]) return cout << "NO\n", 0;
    }

    int ans = -1e9;

    for (int root = 1; root <= n; root++) {
        for (int i = 1; i <= n; i++) {
            if (col[i] % 2 != col[root] % 2) range[i] = {1, 999999};
            else range[i] = {0, 1000000};
        }

        range[root] = {0, 0};
        queue<int> q;
        q.push(root);


        bool fail = 0;
        
        while (!q.empty()) {
            int u = q.front(); q.pop();

            ii r = range[u];

            bool toBreak = 0;

            for (int e : g[u]) {
                ii tmp = r;
                if (enEdge[u][e]) {
                    tmp = {tmp.x + 1, tmp.y + 1};
                } else if (enEdge[e][u]) {
                    tmp = {tmp.x - 1, tmp.y - 1};
                } else tmp = {tmp.x - 1, tmp.y + 1};
                if (tmp.x <= range[e].x && tmp.y >= range[e].y) continue;
                if (tmp.x > range[e].y || tmp.y < range[e].x) {
                    toBreak = 1;
                    break;
                }
                range[e].x = max(range[e].x, tmp.x);
                range[e].y = min(range[e].y, tmp.y);
                q.push(e);
            }
            
            if (toBreak) {
                fail = 1;
                break;
            }
        }

        if (fail) continue;

        if (!fail) {
            int mx = 0;
            for (int i = 1; i <= n; i++) {
                mx = max(mx, range[i].y);
            }
            if (mx <= ans) continue;
            for (int i = 1; i <= n; i++) {
                res[i] = range[i].y;
                ans = max(ans, range[i].y); 
            }
        }
    }

    if (ans != -1e9) {
        cout << "YES\n";
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << '\n';
    } else cout << "NO\n";

    return 0;
}