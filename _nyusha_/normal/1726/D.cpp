#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
vector < pair < int, int > > g[maxn];
int good[maxn], used[maxn];
pair < int, int > edge[maxn];

int dfs(int v, int p) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (u.first == p || !good[u.second]) continue;
        if (!used[u.first]) {
            int val = dfs(u.first, v);
            if (val != -1) return val;
        }
        else {
            return u.second;
        }
    }
    return -1;
}

int find(int n) {
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
        random_shuffle(g[i].begin(), g[i].end());
    }
    return dfs(rand() % n + 1, 0);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, u, v;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) g[i] = {};
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            edge[i] = {u, v};
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
        while (1) {
            set < int > was;
            for (int i = 1; i <= m; i++) good[i] = 1;
            while (1) {
                int val = find(n);
                if (val == -1) break;
                good[val] = 0;
                was.insert(edge[val].first);
                was.insert(edge[val].second);
            }
            if ((int)was.size() != 3 || m - n != 2) {
                for (int i = 1; i <= n; i++) used[i] = 0;
                assert(find(n) == -1);
                for (int i = 1; i <= n; i++) assert(used[i]);
                for (int i = 1; i <= m; i++) cout << good[i];
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}