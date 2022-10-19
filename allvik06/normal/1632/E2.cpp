#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <random>
#include <array>

using namespace std;
const int INF = 1e9;
vector <vector <int>> g;
vector <int> gl, dp;
vector <bool> on_path;

void dfs(int v, int p) {
    for (int i : g[v]) {
        if (i == p) continue;
        gl[i] = gl[v] + 1;
        dfs(i, v);
    }
}

void dfs1(int v, int p, int u) {
    if (v == u) on_path[v] = true;
    dp[v] = gl[v];
    for (int i : g[v]) {
        if (i == p) continue;
        dfs1(i, v, u);
        on_path[v] = on_path[v] || on_path[i];
        if (!on_path[i]) dp[v] = max(dp[v], dp[i]);
    }
}

struct SegTree {
    vector <int> t;

    void build(int v, int l, int r, vector <int>& all) {
        if (l == r) {
            t[v] = all[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, all);
        build(2 * v + 1, m + 1, r, all);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    SegTree(int n, vector <int>& a) {
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    int get_max(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return -INF;
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return max(get_max(2 * v, l, m, A, B), get_max(2 * v + 1, m + 1, r, A, B));
    }

};


signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.assign(n, {});
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        gl.assign(n, 0);
        dp.assign(n, 0);
        on_path.assign(n, false);
        dfs(0, -1);
        int max_v = 0;
        for (int i = 0; i < n; ++i) {
            if (gl[i] > gl[max_v]) max_v = i;
        }
        dfs1(0, -1, max_v);
        vector<pair<int, int>> flex;
        for (int i = 0; i < n; ++i) {
            if (on_path[i]) flex.emplace_back(gl[i], i);
        }
        sort(flex.begin(), flex.end());
        vector<int> all1, all2;
        for (auto i: flex) {
            all1.push_back(dp[i.second] - 2 * i.first);
            all2.push_back(dp[i.second]);
        }
        int len = (int) all1.size();
        SegTree t1(len, all1), t2(len, all2);
        for (int c = 1; c <= n; ++c) {
            if (c >= gl[max_v]) {
                cout << gl[max_v] << " ";
                continue;
            }
            int l = c - 1, r = gl[max_v];
            while (r - l > 1) {
                int m = (l + r) / 2;
                int ind = len - 1 - (m - c);
                int h = (c + ind + 1) / 2;
                int maxx1 = t1.get_max(1, 0, len - 1, h, ind) + c + ind;
                int maxx2 = t2.get_max(1, 0, len - 1, 0, h - 1);
                if (max(maxx1, maxx2) <= m) r = m;
                else l = m;
            }
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
3 4
0 0 0
+ 1
+ 2
+ 2
- 1
 */