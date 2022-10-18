#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
vector < int > g[maxn];
int dist[2][maxn];
int used[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    vector < int > good;
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        good.push_back(x);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector < int > Q = {1};
    int head = 0;
    used[1] = 1;
    while (head < (int)Q.size()) {
        u = Q[head];
        head++;
        //cout << u << ' ';
        for (auto key : g[u]) {
            if (used[key]) continue;
            Q.push_back(key);
            used[key] = 1;
            dist[0][key] = dist[0][u] + 1;
        }
    }
    //cout << endl;
    int ans = dist[0][n];
    Q = {n};
    head = 0;
    used[n] = 2;
    while (head < (int)Q.size()) {
        u = Q[head];
        head++;
        for (auto key : g[u]) {
            if (used[key] == 2) continue;
            used[key] = 2;
            Q.push_back(key);
            dist[1][key] = dist[1][u] + 1;
        }
    }
    //cout << endl;
    //for (int i = 1; i <= n; ++i) cout << dist[0][i] << " " << dist[1][i] << endl;
    multiset < int > T;
    for (int i = 1; i <= k; ++i) {
        T.insert(dist[1][good[i - 1]]);
    }
    int cur = 0;
    sort(good.begin(), good.end(), [](int x, int y) {
        return dist[0][x] < dist[0][y];
    });
    for (auto key : good) {
        T.erase(T.find(dist[1][key]));
        if ((int)T.size() != 0) cur = max(cur, dist[0][key] + (*T.rbegin()) + 1);
    }
    cout << min(ans, cur) << '\n';
    return 0;
}