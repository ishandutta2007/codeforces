#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
#define ll long long
vector <vector <int>> g;
vector <int> ans, p, root, used, ind;

void dfs(int v) {
    used[v] = 1;
    int cur = v;
    while (true) {
        if (p[cur] != -1) {
            if (root[cur] == root[p[cur]]) {
                if (ind[cur] <= ind[p[cur]]) {
                    cout << 0;
                    exit(0);
                }
            } else {
                if (used[root[p[cur]]] == 1) {
                    cout << 0;
                    exit(0);
                }
                if (!used[root[p[cur]]]) dfs(root[p[cur]]);
            }
        }
        if (g[cur].empty()) break;
        cur = g[cur][0];
    }
    cur = v;
    while (true) {
        ans.push_back(cur);
        if (g[cur].empty()) break;
        cur = g[cur][0];
    }
    used[v] = 2;
}

int main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, k;
    cin >> n >> k;
    g.resize(n);
    p.resize(n);
    root.resize(n);
    ind.resize(n);
    vector <int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        ++c[y];
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] > 1 || (int)g[i].size() > 1) {
            cout << 0;
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i]) continue;
        int cur = i;
        root[i] = i;
        int cc = 1;
        while (!g[cur].empty()) {
            cur = g[cur][0];
            root[cur] = i;
            ind[cur] = cc;
            ++cc;
        }
        cnt += cc;
    }
    if (cnt < n) {
        cout << 0;
        return 0;
    }
    used.resize(n);
    for (int i = 0; i < n; ++i) {
        if (!used[root[i]]) dfs(root[i]);
    }
    for (int i : ans) cout << i + 1 << " ";
}