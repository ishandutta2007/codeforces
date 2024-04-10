#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>

using namespace std;

struct dsu {
    int n;
    vector <int> p;

    dsu(int n) : n(n) {
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int parent(int v) {
        if (v == p[v]) return v;
        p[v] = parent(p[v]);
        return p[v];
    }

    inline bool unite(int a, int b) {
        a = parent(a);
        b = parent(b);
        if (a == b) return false;
        p[a] = b;
        return true;
    }
};

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> g(n);
    vector <pair <int, int>> bad;
    dsu now(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        if (now.unite(x, y)) {
            g[x].push_back(y);
            g[y].push_back(x);
        } else {
            bad.emplace_back(x, y);
        }
    }
    vector <int> tin(n), tout(n);
    int cur_time = 0;

    function <void(int, int)> dfs = [&](int v, int p) {
        if (p >= 0) g[v].erase(std::find(g[v].begin(), g[v].end(), p));
        tin[v] = cur_time++;
        for (int i : g[v]) {
            dfs(i, v);
        }
        tout[v] = cur_time++;
    };

    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end(), [&](int a, int b) {
            return tin[a] < tin[b];
        });
    }

    vector <int> cnt(n), sum(n);

    for (auto i : bad) {
        int x = i.first;
        int y = i.second;
        if (tin[x] > tin[y]) swap(x, y);
        if (tin[y] <= tout[x]) {
            int flex = g[x][upper_bound(g[x].begin(), g[x].end(), y, [&](int a, int b) {
                return tin[a] < tin[b];
            }) - g[x].begin() - 1];
            ++cnt[0];
            ++cnt[y];
            --cnt[flex];
        } else {
            ++cnt[x];
            ++cnt[y];
        }
    }

    function <void(int)>dfs2 = [&](int v) {
        sum[v] += cnt[v];
        for (int i : g[v]) {
            cnt[i] += cnt[v];
            dfs2(i);
        }
    };

    dfs2(0);
    for (int i = 0; i < n; ++i) {
        if (sum[i] == (int)bad.size()) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
       // cin >> t;
        while (t--) {
            solve();
        }
    } else {

    }
}

/*

 */