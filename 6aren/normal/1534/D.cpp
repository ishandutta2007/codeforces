#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<set<int>> g(n + 1);
    vector<vector<int>> vs(2);
    cout << "? " << 1 << endl;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        if (u == 1) {
            g[1].insert(i);
            g[i].insert(1);
        }
        if (i > 1) vs[u % 2].push_back(i);
    }
    vector<int> to_check = (vs[0].size() < vs[1].size() ? vs[0] : vs[1]);

    for (int e : to_check) {
        cout << "? " << e << endl;
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            if (u == 1) {
                g[e].insert(i);
                g[i].insert(e);
            }
        }
    }

    set<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int e : g[i]) {
            int u = i;
            int v = e;
            if (u > v) swap(u, v);
            edges.insert(make_pair(u, v)); 
        }
    }

    cout << "!" << endl;
    for (auto e : edges) cout << e.first << ' ' << e.second << endl;

    return 0;
}