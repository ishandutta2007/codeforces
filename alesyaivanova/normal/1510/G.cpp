#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 102;
const int INF = 1e9 + 239;

int n, k;
vector<int> g[N];

int sz[N];
int wr[N];
int in[N];

void dfs1(int cur, int p, int h, int w) {
    if (h == 1) {
        w = cur;
    }
    wr[cur] = w;
    for (auto t : g[cur]) {
        if (t != p) {
            dfs1(t, cur, h + 1, w);
        }
    }
}

int ans;
int targ;
int cgo;

void dfs2(int cur, int p, int h) {
    sz[cur] = 1;
    for (auto t : g[cur]) {
        if (t != p) {
            dfs2(t, cur, h + 1);
            sz[cur] += sz[t];
        }
    }
    if (h < k && n - sz[cur] + 1 >= k) {
        int path = h;
        int not_path = k - h;
        if (ans > path + 2 * not_path) {
            ans = path + 2 * not_path;
            targ = cur;
            cgo = not_path - 1;
        }
    }
}

vector<int> st;
vector<int> res;

void dfs3(int cur, int p) {
    if (cur == targ) {
        for (auto v : st) {
            in[v] = 1;
        }
        return;
    }
    for (auto v : g[cur]) {
        if (v != p) {
            st.push_back(v);
            dfs3(v, p);
            st.pop_back();
        }
    }
}

void dfs4(int cur, int p) {
    res.push_back(cur);
    for (auto t : g[cur]) {
        if (!in[t] && t != p && cgo > 0) {
            cgo--;
            dfs4(t, cur);
            res.push_back(cur);
        }
    }
    for (auto t : g[cur]) {
        if (in[t] && t != p) {
            dfs4(t, cur);
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        g[i].clear();
        wr[i] = -1;
        sz[i] = 0;
        in[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    dfs1(0, -1, 0, -1);
    ans = INF;
    targ = -1;
    dfs2(0, -1, 0);
    st = {};
    dfs3(0, -1);
    res = {};
    dfs4(0, -1);
    cout << (int)res.size() - 1 << endl;
    for (auto t : res) {
        cout << t + 1 << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}