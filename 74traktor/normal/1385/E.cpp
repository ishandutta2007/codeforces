#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
vector < int > g[maxn];
int used[maxn], ok, pos[maxn], cur;

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u] == 0) {
            dfs(u);
        }
        else if (used[u] == 1) ok = 0;
    }
    used[v] = 2;
    pos[v] = cur++;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, u, v, t;
        cin >> n >> m;
        vector < pair < int, int > > check;
        for (int i = 1; i <= n; ++i) g[i] = {}, used[i] = 0;
        for (int i = 1; i <= m; ++i) {
            cin >> t >> u >> v;
            if (t == 1) {
                g[u].push_back(v);
            }
            else {
                check.push_back({u, v});
            }
        }
        ok = 1;
        cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (used[i] == 0) dfs(i);
        }
        if (!ok) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i = 1; i <= n; ++i) {
            for (auto elem : g[i]) cout << i << " " << elem << '\n';
        }
        for (auto key : check) {
            if (pos[key.first] > pos[key.second]) cout << key.first << " " << key.second << '\n';
            else cout << key.second << " " << key.first << '\n';
        }
    }
    return 0;
}