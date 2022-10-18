#include<bits/stdc++.h>

using namespace std;

vector < int > g[1005];
vector < int > a;
int sz = 0;

void dfs(int v, int p, int d) {
    if ((int)g[v].size() <= 1) a.push_back(d);
    for (auto u : g[v]) {
        if (u != p) dfs(u, v, d + 1);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, u, v;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        a = {};
        for (int i = 1; i <= n; ++i) g[i] = {};
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(x, -1, 0);
        sort(a.begin(), a.end());
        if (a[0] == 0) {
            cout << "Ayush" << '\n';
            continue;
        }
        if ((n - 1) % 2 == 0) cout << "Ashish" << '\n';
        else cout << "Ayush" << '\n';
    }
    return 0;
}