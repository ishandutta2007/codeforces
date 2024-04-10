#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector <vector <int>> g;
vector <int> sz, used;
vector <bool> centr;

void calc_sz(int v, int lvl) {
    used[v] = lvl;
    sz[v] = 1;
    for (int i : g[v]) {
        if (used[i] == lvl || centr[i]) continue;
        calc_sz(i, lvl);
        sz[v] += sz[i];
    }
}

int find_centroid(int v, int p, int big_sz) {
    for (int i : g[v]) {
        if (centr[i] || i == p) continue;
        if (2 * sz[i] > big_sz) return find_centroid(i, v, big_sz);
    }
    return v;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    used.resize(n);
    sz.resize(n);
    centr.resize(n);
    vector <char> ans(n);
    for (int lvl = 1; ; ++lvl) {
        bool f = false;
        for (int i = 0; i < n; ++i) {
            if (used[i] == lvl || centr[i]) continue;
            f = true;
            calc_sz(i, lvl);
            int c = find_centroid(i, -1, sz[i]);
            centr[c] = true;
            ans[c] = 'A' + lvl - 1;
        }
        if (!f) break;
    }
    for (char c : ans) cout << c << " ";
}