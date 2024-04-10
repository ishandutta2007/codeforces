#include <bits/stdc++.h>

using namespace std;

int const maxn = 500005;
int used[maxn];
vector < pair < int, int > > g[maxn];
bool check = true;
vector < int > topsort;
int ans[maxn];

void dfs1(int v, int h) {
    used[v] = 3;
    if (h == 3) h = 1;
    for (auto u : g[v]) {
        ans[u.second] = h;
        if (used[u.first] == 2) {
            dfs1(u.first, h + 1);
        }
    }
}

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u.first] == 1) check = false;
        if (used[u.first] == 0) dfs(u.first);
    }
    used[v] = 2;
    topsort.push_back(v);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector < pair < int, int > > inp;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back({v, i});
        inp.push_back({u, v});
    }
    for (int i = 1; i <= n; ++i) random_shuffle(g[i].begin(), g[i].end());
    for (int i = 1; i <= n; ++i) if (used[i] == 0) dfs(i);
    if (check) {
        cout << 1 << '\n';
        for (int i = 1; i <= m; ++i) cout << 1 << " ";
        cout << '\n';
        return 0;
    }
    cout << 2 << '\n';
    for (int i = 0; i < m; ++i) {
        if (inp[i].first > inp[i].second) cout << 2 << " ";
        else cout << 1 << " ";
    }
    return 0;
}