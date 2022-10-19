#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
vector <vector <pair <int, int>>> g;
vector <bool> good;
vector <int> st;

bool dfs(int v, int b, vector <int>& cmp, int num) {
    st.push_back(v);
    cmp[v] = num;
    bool ok = good[v];
    for (auto i : g[v]) {
        if (!(i.second & b) || cmp[i.first] != -1) continue;
        ok |= dfs(i.first, b, cmp, num);
    }
    return ok;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    g.resize(n);
    good.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w; --x; --y;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
        if (!(w & 1)) good[x] = good[y] = true;
    }
    vector <vector <int>> cmp(30, vector <int> (n, -1));
    vector <bool> gen(n);
    for (int b = 0; b < 30; ++b) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cmp[b][i] != -1) continue;
            if (dfs(i, (1 << b), cmp[b], cur) && b) {
                for (int j : st) gen[j] = true;
            }
            ++cur;
            st.clear();
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y; --x; --y;
        bool ok = false;
        for (int b = 0; b < 30; ++b) {
            if (cmp[b][x] == cmp[b][y]) ok = true;
        }
        if (ok) cout << "0\n";
        else if (gen[x]) cout << "1\n";
        else cout << "2\n";
    }
}