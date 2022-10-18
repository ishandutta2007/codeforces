#include <bits/stdc++.h>

using namespace std;

#define int long long
vector < int > g[61];
vector < int > G[100005];
int a[100005];
int dist[100005];
int used[100005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 60; ++j) if ((a[i]&(1ll << j))) g[j].push_back(i);
    }
    for (int j = 0; j < 60; ++j) {
        if ((int)g[j].size() > 2) {
            cout << 3 << '\n';
            return 0;
        }
        if ((int)g[j].size() == 2) G[g[j][0]].push_back(g[j][1]), G[g[j][1]].push_back(g[j][0]);
    }
    int ans = n + 7, cur = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto key : G[i]) {
            cur++;
            dist[i] = 0;
            used[i] = cur;
            int head = 0;
            vector < int > Q;
            for (auto go : G[i]) {
                if (key != go) {
                    dist[go] = 1, used[go] = cur, Q.push_back(go);
                }
            }
            while (head < (int)Q.size()) {
                int d = Q[head];
                for (auto u : G[d]) {
                    if (used[u] == cur) continue;
                    dist[u] = dist[d] + 1;
                    used[u] = cur;
                    Q.push_back(u);
                }
                head++;
            }
            //if (dist[key] == 1) cout << i << " " << key << '\n';
            if (used[key] == cur) ans = min(ans, dist[key]);
        }
    }
    if (ans == n + 7) cout << -1 << '\n';
    else cout << ans + 1 << '\n';
    return 0;
}