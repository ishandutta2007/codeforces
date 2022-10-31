#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int d[maxn];
int inf = 1e9 + 7;
int lst[maxn];
int was[maxn];
vector < pair < int, int > > g[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, U, V, w;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> U >> V >> w;
        g[U].push_back({V, w});
        g[V].push_back({U, w});
    }
    for (int i = 1; i <= n; ++i) d[i] = inf, was[i] = 51;
    priority_queue < pair < int, int > > Q;
    d[1] = 0;
    Q.push({0, 1});
    while ((int)Q.size() > 0) {
        auto p = Q.top();
        Q.pop();
        if (d[p.second] < -p.first) continue;
        for (auto u : g[p.second]) {
            if (u.second >= was[u.first]) continue;
            was[u.first] = u.second;
            for (auto elem : g[u.first]) {
                int c = -p.first + (elem.second + u.second) * (elem.second + u.second);
                if (c < d[elem.first]) {
                    d[elem.first] = c;
                    Q.push({-c, elem.first});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i] == inf) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    return 0;
}