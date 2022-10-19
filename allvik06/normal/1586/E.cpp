#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> g, gg;
vector <bool> used;
vector <int> st;
void dfs(int v) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) {
            gg[v].push_back(i);
            gg[i].push_back(v);
            dfs(i);
        }
    }
}

bool dfs1(int v, int p, int to) {
    st.push_back(v);
    if (v == to) return true;
    for (int i : gg[v]) {
        if (i != p) {
            if (dfs1(i, v, to)) return true;
        }
    }
    st.pop_back();
    return false;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m, q;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    gg.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    cin >> q;
    vector <pair <int, int>> all_q(q);
    vector <int> p(n);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        all_q[i] = make_pair(x, y);
        ++p[x];
        ++p[y];
    }
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        cnt1 += p[i] % 2;
    }
    if (cnt1 == 0) {
        cout << "YES\n";
        for (int i = 0; i < q; ++i) {
            dfs1(all_q[i].first, -1, all_q[i].second);
            cout << st.size() << "\n";
            for (int j : st) cout << j + 1 << " ";
            cout << "\n";
            st.clear();
        }
    } else {
        cout << "NO\n" << cnt1 / 2;
    }
}