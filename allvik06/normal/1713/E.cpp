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
#include <cstring>

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

vector <vector <pair <int, int>>> g;
vector <int> val, used;

void dfs(int v) {
    used[v] = 1;
    for (auto i : g[v]) {
        if (!used[i.first]) {
            val[i.first] = (val[v] ^ i.second);
            dfs(i.first);
        }
    }
}

void solve1() {
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    g.assign(n, {});
    dsu now(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] == a[j][i]) continue;
            int x = (a[i][j] > a[j][i]);
            if (now.unite(i, j)) {
                g[i].emplace_back(j, x);
                g[j].emplace_back(i, x);
            }
        }
    }
    used.assign(n, 0);
    val.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        if (val[i]) {
            for (int j = 0; j < n; ++j) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
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