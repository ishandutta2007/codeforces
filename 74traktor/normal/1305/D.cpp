#include<bits/stdc++.h>

using namespace std;

int const maxn = 1005;
set < int > g[maxn];
int n;
vector < int > T, go;

void dfs1(int v, int p) {
    T.push_back(v);
    if ((int)T.size() > 2 && (int)go.size() == 0) go = T;
    for (auto u : g[v]) if (u != p) dfs1(u, v);
    T.pop_back();
}

void dfs2(int v, int p) {
    T.push_back(v);
    if ((int)T.size() > (int)go.size()) go = T;
    for (auto u : g[v]) if (u != p) dfs2(u, v);
    T.pop_back();
}

void dfs(int v) {
    if ((int)g[v].size() == 0) {
        cout << "! " << v << endl;
        exit(0);
    }
    go = {};
    dfs1(v, -1);
    if ((int)go.size() == 0) {
        for (auto u : g[v]) {
            dfs1(u, -1);
            if ((int)go.size() != 0) break;
        }
    }
    dfs2(v, -1);
    cout << "? " << go[0] << " " << go.back() << endl;
    int x;
    cin >> x;
    for (int j = 0; j < (int)go.size(); ++j) {
        if (go[j] == x) {
            if (j != 0) g[x].erase(go[j - 1]);
            if (j + 1 != (int)go.size()) g[x].erase(go[j + 1]);
        }
    }
    dfs(x);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    dfs(1);
    return 0;
}