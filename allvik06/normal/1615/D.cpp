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
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;

struct dsu {
    vector <int> p;

    dsu(int n) {
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

vector <vector <pair <int, int>>> g, gg;

void dfs(int v, int p, dsu& now) {
    for (auto i : g[v]) {
        if (i.first == p) continue;
        if (i.second != -1) {
            int cnt = __builtin_popcount(i.second) % 2;
            now.unite(v, i.first);
            gg[v].emplace_back(i.first, cnt);
            gg[i.first].emplace_back(v, cnt);
        }
        dfs(i.first, v, now);
    }
}

vector <int> p;
vector <bool> used;

void set_values(int v) {
    used[v] = true;
    for (auto i : gg[v]) {
        if (used[i.first]) continue;
        p[i.first] = p[v] ^ i.second;
        set_values(i.first);
    }
}

void print_ans(int v, int pr) {
    for (auto i : g[v]) {
        if (pr == i.first) continue;
        if (i.second != -1) cout << v + 1 << " " << i.first + 1 << " " << i.second << "\n";
        else {
            cout << v + 1 << " " << i.first + 1 << " " << (p[v] ^ p[i.first]) << "\n";
        }
        print_ans(i.first, v);
    }
}

void solve1() {
    int n, m;
    cin >> n >> m;
    dsu now(n);
    g.assign(n, {});
    gg.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
        int x, y, w;
        cin >> x >> y >> w; --x; --y;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    dfs(0, -1, now);
    vector <array <int, 3>> all_q(m);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w; --x; --y;
        if (now.unite(x, y)) {
            gg[x].emplace_back(y, w);
            gg[y].emplace_back(x, w);
        }
        all_q[i] = {x, y, w};
    }
    p.assign(n, 0);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) set_values(i);
    }
    bool ok = true;
    for (auto i : all_q) {
        if ((p[i[0]] ^ p[i[1]]) != i[2]) ok = false;
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    print_ans(0, -1);
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */