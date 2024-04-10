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
#define int long long
const int INF = 1e9;

struct dsu {
    int n;
    vector <int> p, sz;

    dsu(int n) : n(n) {
        p.resize(n);
        sz.resize(n, 1);
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
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        return true;
    }
};
vector <vector <int>> g;
vector <int> st;

bool dfs(int v, int p, int need) {
    st.push_back(v);
    if (need == v) return true;
    for (int i : g[v]) {
        if (i == p) continue;
        if (dfs(i, v, need)) return true;
    }
    st.pop_back();
    return false;
}

void solve1() {
    int n, m;
    cin >> n >> m;
    st.clear();
    vector <pair <int, int>> a(m);
    g.assign(n, {});
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second; --a[i].first; --a[i].second;
    }
    string res;
    vector <int> flex;
    dsu now(n);
    int cur = 0;
    vector <int> c(n);
    for (auto i : a) {
        if (now.unite(i.first, i.second)) {
            res += "0";
            g[i.first].push_back(i.second);
            g[i.second].push_back(i.first);
        } else {
            res += "1";
            flex.push_back(cur);
            ++c[i.first];
            ++c[i.second];
        }
        cur++;
    }
    if ((int)flex.size() != 3) {
        cout << res << "\n";
        return;
    }
    for (int i : c) {
        if (i != 0 && i != 2) {
            cout << res << "\n";
            return;
        }
    }
    dfs(a[flex[0]].first, -1, a[flex[0]].second);
    res[flex[0]] = '0';
    for (int i = 0; i < m; ++i) {
        if (a[i].first == st[0] && a[i].second == st[1]) {
            res[i] = '1';
            break;
        }
        if (a[i].first == st[1] && a[i].second == st[0]) {
            res[i] = '1';
            break;
        }
    }
    cout << res << "\n";
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