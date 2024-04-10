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
    int n;
    vector <int> p, sz;

    dsu(int n) {
        p.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int parent(int v) {
        if (p[v] == v) return v;
        p[v] = parent(p[v]);
        return p[v];
    }

    inline bool unite(int a, int b) {
        a = parent(a);
        b = parent(b);
        if (a == b) return false;
        p[a] = b;
        sz[b] += sz[a];
        return true;
    }

    inline bool single(int v) {
        if (sz[parent(v)] == 1) return true;
        return false;
    }
};

inline int ask(int v) {
    cout << "? " << v + 1 << endl;
    int x;
    cin >> x;
    return x - 1;
}

inline void solve() {
    int n;
    cin >> n;
    vector <int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    vector <pair <int, int>> a;
    for (int i = 0; i < n; ++i) a.emplace_back(d[i], i);
    sort(a.rbegin(), a.rend());
    dsu now(n);
    for (auto i : a) {
        int dd = i.first;
        int v = i.second;
        if (!now.single(v)) continue;
        for (int j = 0; j < dd; ++j) {
            int pr = ask(v);
            if (!now.single(pr)) {
                now.unite(v, pr);
                break;
            } else {
                now.unite(v, pr);
            }
        }
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) cout << now.parent(i) + 1 << " ";
    cout << endl;
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
            solve();
        }
        //  while (true) {}
    }
}

/*

 */