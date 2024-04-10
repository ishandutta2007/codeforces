#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
vector < int > g[maxn];
int start[maxn], cost[maxn];
map < int, int > add[maxn];
int link[maxn];
int del[maxn];

void dfs(int v) {
    for (auto u : g[v]) {
        dfs(u);
    }
    if ((int)g[v].size() == 0) {
        add[v][0] = 0;
        add[v][start[v]] = cost[v];
        link[v] = v;
        return;
    }
    link[v] = link[g[v][0]];
    for (auto u : g[v]) {
        if (u == g[v][0]) continue;
        for (auto key : add[link[u]]) {
            add[link[v]][key.first] += key.second;
        }
    }
    if (start[v] != 0) {
        add[link[v]][start[v]] += cost[v];
        int good = 0, ptr = 1;
        auto it = add[link[v]].upper_bound(start[v]);
        while (it != add[link[v]].end()) {
            good += (*it).second;
            if (good >= cost[v]) {
                //if (v == 4) cout << good << " " << cost[v] << endl;
                add[link[v]][(*it).first] = (good - cost[v]);
                break;
            }
            del[ptr++] = (*it).first;
            it++;
        }
        for (int j = 1; j < ptr; ++j) add[link[v]].erase(del[j]);
    }
    /*if (v == 4) {
        int sum = 0;
        for (auto key : add[link[v]]) {
            sum += key.second;
            cout << key.first << " " << sum << endl;
        }
        exit(0);
    }*/
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, d, w;
    cin >> n >> m >> k;
    for (int i = 2; i <= n; ++i) {
        cin >> u;
        g[u].push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> u >> d >> w;
        start[u] = d, cost[u] = w;
    }
    dfs(1);
    int sum = 0, ans = 0, lst = 0;
    for (auto key : add[link[1]]) {
        sum += key.second;
        if (sum < lst) {
            cout << 1 / 0 << endl;
            exit(0);
        }
        lst = sum;
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}