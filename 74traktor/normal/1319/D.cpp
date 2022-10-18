#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
vector < int > g[maxn], G[maxn];
int dist[2][maxn];
int n;
int cnt[maxn];

void bfs(int v, int p) {
    for (int i = 1; i <= n; ++i) dist[p][i] = 10000000;
    dist[p][v] = 0;
    vector < int > Q = {v};
    int head = 0;
    while (head < (int)Q.size()) {
        int u = Q[head++];
        for (auto to : g[u]) {
            if (dist[p][u] + 1 < dist[p][to]) {
                dist[p][to] = dist[p][u] + 1;
                Q.push_back(to);
            }
        }
    }
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[v].push_back(u);
        G[u].push_back(v);
    }
    int k;
    cin >> k;
    vector < int > f;
    for (int i = 1; i <= k; ++i) {
        cin >> v;
        f.push_back(v);
    }
    int ans1 = 0, ans2 = 0;
    bfs(f.back(), 1);
    for (int i = 1; i <= n; ++i) {
        for (auto u : G[i]) {
            if (dist[1][i] == dist[1][u] + 1) cnt[i]++;
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        //cout << dist[1][f[i + 1]] + 1 << " " << dist[1][f[i]] << endl;
        if (dist[1][f[i + 1]] + 1 != dist[1][f[i]]) ans1++, ans2++;
        else {
            if (cnt[f[i]] > 1) ans2++;
        }
        //cout << ans2 << endl;
    }
    cout << ans1 << " " << ans2 << '\n';
    return 0;
}