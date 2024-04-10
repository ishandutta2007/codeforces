#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
vector <vector <int>> g, bp;
vector <vector <pair <int, int>>> flex;
vector <int> gl, tin, tout;

int tim = 0;
void dfs(int v, int p) {
    tin[v] = tim++;
    for (int i : g[v]) {
        if (i == p) continue;
        gl[i] = gl[v] + 1;
        bp[0][i] = v;
        dfs(i, v);
        flex[v].emplace_back(tout[i], i);
    }
    tout[v] = tim++;
}

inline bool check(int a, int b) {
    if (tin[a] <= tin[b] && tin[b] <= tout[a]) return true;
    return false;
}

inline void build(int n) {
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            bp[i][j] = bp[i - 1][bp[i - 1][j]];
        }
    }
}

inline int parent(int v, int k) {
    for (int i = 19; i >= 0; --i) {
        if (k >= (1 << i)) {
            k -= (1 << i);
            v = bp[i][v];
        }
    }
    return v;
}

inline int lca(int a, int b) {
    if (gl[a] < gl[b]) swap(a, b);
    a = parent(a, gl[a] - gl[b]);
    if (a == b) return a;
    for (int i = 19; i >= 0; --i) {
        if (bp[i][a] != bp[i][b]) {
            a = bp[i][a];
            b = bp[i][b];
        }
    }
    return bp[0][a];
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n;
    g.resize(n);
    flex.resize(n);
    bp.resize(20, vector <int> (n + 1, n));
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> q;
    gl.resize(n);
    tin.resize(n);
    tout.resize(n);
    dfs(0, -1);
    build(n);
    while (q--) {
        int k;
        cin >> k;
        set <pair <int, int>> all;
        flex.resize(n);
        int st = -1, l = -1;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x; --x;
            all.insert(make_pair(gl[x], x));
            if (st == -1 || gl[x] > gl[st]) st = x;
            if (l == -1) l = x;
            else l = lca(l, x);
        }
        all.insert(make_pair(gl[l], l));
        set <pair <int, int>> all2;
        all.erase(make_pair(gl[st], st));
        int prev = -1;
        while (!all.empty()) {
            pair <int, int> now = *all.rbegin();
            all.erase(now);
            if (check(now.second, st)) {
                prev = st;
                st = now.second;
                continue;
            }
            all2.insert(now);
        }
        bool ok = true;
        while (!all2.empty()) {
            pair <int, int> now = *all2.begin();
            all2.erase(now);
            if (check(st, now.second)) {
                st = now.second;
                continue;
            }
            ok = false;
            break;
        }
        if (st != l && prev != -1) {
            auto it = lower_bound(flex[l].begin(), flex[l].end(), make_pair(tin[st], -1));
            int c1 = it->first;
            it = lower_bound(flex[l].begin(), flex[l].end(), make_pair(tin[prev], -1));
            int c2 = it->first;
            if (c1 == c2) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*

 */