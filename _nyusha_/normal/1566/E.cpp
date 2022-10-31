#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
set < int > g[maxn];
int inf = 1e9 + 7;
int p[maxn];
vector < int > tmp;
int sum[maxn];

int dfs(int v, int lst) {
    p[v] = lst;
    int child = 0;
    sum[v] = 0;
    for (auto u : g[v]) {
        if (u != lst) child++, sum[v] += dfs(u, v);
    }
    if (child == sum[v] && child) tmp.push_back(v);
    if (v != 1 && (int)g[v].size() == 1) return 1;
    return 0;
}

int get_child(int v) {
    if (v == 1) return g[v].size();
    return g[v].size() - 1;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) g[i] = {};
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
        }
        tmp.clear();
        int lists = 0;
        for (int i = 2; i <= n; ++i) {
            if ((int)g[i].size() == 1) lists++;
        }
        dfs(1, 0);
        int cost = 0;
        int head = 0;
        while (head < (int)tmp.size()) {
            int now = tmp[head++];
            cost++;
            if (now == 1) break;
            //cout << now << endl;
            if (p[now] != 1) {
                if ((int)g[p[now]].size() == 2) {
                    cost--;
                    sum[p[p[now]]]++;
                    if (sum[p[p[now]]] == get_child(p[p[now]])) {
                        tmp.push_back(p[p[now]]);
                    }
                }
            }
            for (auto key : g[now]) {
                g[key].erase(now);
            }
            g[now] = {};
            if (now != 1) {
                if (sum[p[now]] == get_child(p[now]) && sum[p[now]] != 0) tmp.push_back(p[now]);
            }
        }
        cout << lists + 1 - cost << '\n';
    }
    return 0;
}