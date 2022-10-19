//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
#define ll long long
ll ans = 0, now = 0;
int cur_sz = 0;
const int MAXN = 5e5 + 10;
vector <vector <pair <int, int>>> g;
vector <int> flex, sz, centr, used, cur;

void calc_sz(int v, int p, int lvl) {
    sz[v] = 1;
    used[v] = lvl;
    for (auto i : g[v]) {
        if (centr[i.first] || i.first == p) continue;
        calc_sz(i.first, v, lvl);
        sz[v] += sz[i.first];
    }
}

int find_centroid(int v, int p, int SZ) {
    for (auto i : g[v]) {
        if (centr[i.first] || i.first == p) continue;
        if (sz[i.first] * 2 > SZ) return find_centroid(i.first, v, SZ);
    }
    return v;
}

void upd_flex(int v, int p, int col, int k) {
    if (!cur[col]) {
        flex[col] += sz[v] * k;
    }
    ++cur[col];
    for (auto i : g[v]) {
        if (centr[i.first] || i.first == p) continue;
        upd_flex(i.first, v, i.second, k);
    }
    --cur[col];
}

void dfs(int v, int p, int col) {
    if (!cur[col]) {
        now += cur_sz - flex[col];
    } else if (cur[col] == 1) {
        now -= cur_sz - flex[col];
    }
    ans += now;
    ++cur[col];
    for (auto i : g[v]) {
        if (centr[i.first] || i.first == p) continue;
        dfs(i.first, v, i.second);
    }
    --cur[col];
    if (!cur[col]) {
        now -= cur_sz - flex[col];
    } else if (cur[col] == 1) {
        now += cur_sz - flex[col];
    }
}

void nul_flex(int v, int p) {
    for (auto i : g[v]) {
        if (centr[i.first] || i.first == p) continue;
        flex[i.second] = 0;
        nul_flex(i.first, v);
    }
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    g.resize(n);
    flex.resize(n);
    centr.resize(n);
    used.resize(n);
    cur.resize(n);
    sz.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, w;
        cin >> x >> y >> w; --x; --y; --w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    for (int it = 1;; ++it) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (centr[i] || used[i] == it) continue;
            ok = true;
            calc_sz(i, -1, it);
            int c = find_centroid(i, -1, sz[i]);
            calc_sz(c, -1, it);
            cur_sz = sz[c];
            for (auto j : g[c]) {
                if (used[j.first] == it) {
                    upd_flex(j.first, c, j.second, 1);
                }
            }
            for (auto j : g[c]) {
                if (used[j.first] == it) {
                    cur_sz -= sz[j.first];
                    upd_flex(j.first, c, j.second, -1);
                    dfs(j.first, c, j.second);
                    upd_flex(j.first, c, j.second, 1);
                    cur_sz += sz[j.first];
                }
            }
            nul_flex(c, -1);
            centr[c] = 1;
        }
        if (!ok) break;
    }
    cout << ans;
}

/*

 */