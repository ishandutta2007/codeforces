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
vector <vector <int>> g, kek;
vector <int> cmp, sz, tin, fup, ord, cn;
vector <bool> used;
int now = 0, cur_time = 0;

void dfs(int v, int p) {
    ord.push_back(v);
    cmp[v] = now;
    tin[v] = fup[v] = cur_time++;
    sz[v] = 1;
    for (int i : g[v]) {
        if (cmp[i] == -1) {
            dfs(i, v);
            sz[v] += sz[i];
            fup[v] = min(fup[v], fup[i]);
        } else if (i != p) {
            fup[v] = min(fup[v], tin[i]);
        }
    }
}

void calc_points(int v, int p, int root) {
    used[v] = true;
    int cha = 0;
    if (p != -1) {
        cha = 1;
        for (int i = tin[root]; i < tin[root] + sz[root]; ++i) {
            if (i >= tin[v] && i < tin[v] + sz[v]) continue;
            kek[v][ord[i]] = 0;
        }
    }
    for (int i : g[v]) {
        if (!used[i]) {
            calc_points(i, v, root);
            if (fup[i] < tin[v]) {
                for (int j = tin[i]; j < tin[i] + sz[i]; ++j) kek[v][ord[j]] = 0;
            } else {
                for (int j = tin[i]; j < tin[i] + sz[i]; ++j) kek[v][ord[j]] = cha;
                ++cha;
            }
        }
    }
    cn[v] = cha;
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        now = cur_time = 0;
        ord.clear();
        int n, cnt = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (!a[i]) {
                cnt += ++a[i];
            }
        }
        g.assign(n, {});
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (a[i] & a[j]) g[i].push_back(j);
            }
        }
        tin.assign(n, -1);
        fup.assign(n, -1);
        cmp.assign(n, -1);
        kek.assign(n, vector <int> (n, -1));
        sz.assign(n, 0);
        cn.assign(n, 0);
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (cmp[i] != -1) continue;
            dfs(i, -1);
            calc_points(i, -1, i);
            ++now;
        }
        if (now == 1) {
            cout << cnt << "\n";
            for (int i: a) cout << i << " ";
            cout << "\n";
            continue;
        }
        vector<bool> conn(2 * n);
        bool f = false;
        for (int i = 0; i < n; ++i) {
            for (int x = a[i] - 1; x <= a[i] + 1; x += 2) {
                int cha = 0;
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    if (x & a[j]) {
                        int val = cmp[j];
                        if (cmp[j] == cmp[i]) val = kek[i][j] + n;
                        if (!conn[val]) {
                            ++cha;
                            conn[val] = true;
                        }
                    }
                }
                for (int j = 0; j < 2 * n; ++j) conn[j] = false;
                if (cha == now - 1 + cn[i]) {
                    cout << cnt + 1 << "\n";
                    a[i] = x;
                    for (int j : a) cout << j << " ";
                    cout << "\n";
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (f) continue;
        vector <int> mn_b(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 30; ++j) {
                if ((a[i] >> j) & 1) {
                    mn_b[i] = j;
                    break;
                }
            }
            mx = max(mx, mn_b[i]);
        }
        vector <int> flex;
        for (int i = 0; i < n; ++i) {
            if (mx == mn_b[i]) {
                flex.push_back(i);
            }
        }
        assert((int)flex.size() >= 2);
        a[flex[0]]--;
        a[flex[1]]++;
        cout << cnt + 2 << "\n";
        for (int i : a) cout << i << " ";
        cout << "\n";
    }
}

/*

 */