#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 100005;

int n, m, k, s;
vector<int> g[N];
int a[N];
int d[N];
vector<int> ans[N];

void bfs(int col) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (a[i] == col) {
            q.push(i);
            d[i] = 0;
        } else d[i] = 1e9;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (d[v] == 1e9) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i].pb(d[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= k; i++) {
        bfs(i);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(ans[i]));
        int sum = 0;
        for (int j = 0; j < s; j++) sum += ans[i][j];
        cout << sum << ' ';
    }
    return 0;
}