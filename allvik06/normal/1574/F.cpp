#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define ll long long
const ll mod = 998244353;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m, k, maxl = 0, cnt = 0;
    cin >> n >> m >> k;
    vector <vector <int>> all(n);
    vector <vector <pair <int, int>>> all_s(k);
    vector <bool> bad(k);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        all[i].resize(l);
        map <int, int> d;
        int mx = 0;
        for (int j = 0; j < l; ++j) {
            cin >> all[i][j]; --all[i][j];
            if (d.count(all[i][j])) mx = 1;
            d[all[i][j]] = j;
        }
        if (l == 2) cnt = i;
        for (auto j : d) {
            all_s[j.first].emplace_back(i, j.second);
        }
        if (mx) {
            for (auto j : d) {
                bad[j.first] = true;
            }
        }
    }
    vector <vector <int>> g(n + k), gg(k);
    for (int i = 0; i < k; ++i) {
        for (auto j : all_s[i]) {
            g[j.first].push_back(n + i);
            g[n + i].push_back(j.first);
        }
    }
    vector <int> used(n + k), st, ord, used1(k);

    function <void(int)> dfs = [&](int v) {
        used[v] = 1;
        if (v >= n) st.push_back(v - n);
        for (int i : g[v]) {
            if (!used[i]) {
                dfs(i);
            }
        }
    };

    function <void(int)> top_sort = [&](int v) {
        used1[v] = 1;
        for (int i : gg[v]) {
            if (used1[i] != 1) {
                top_sort(i);
            }
        }
        ord.push_back(v);
    };

    map <int, int> w;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        st.clear();
        ord.clear();
        dfs(i);
        bool ok = true;
        vector <int> now;
        for (int j : st) {
            for (auto x : all_s[j]) now.push_back(x.first);
            if (bad[j]) ok = false;
        }
        if (!ok) continue;
        sort(now.begin(), now.end());
        now.resize(unique(now.begin(), now.end()) - now.begin());
        for (int j : now) {
            for (int l = 0; l < (int)all[j].size() - 1; ++l) {
                gg[all[j][l]].push_back(all[j][l + 1]);
            }
        }
        for (int j : st) {
            if (used1[j] == 1) continue;
            top_sort(j);
        }
        reverse(ord.begin(), ord.end());
        map <int, int> start;
        for (int j = 0; j < (int)ord.size(); ++j) start[ord[j]] = j;
        for (int j : now) {
            int s = start[all[j][0]];
            for (int l = 0; l < (int)all[j].size(); ++l) {
                if (s + l == (int)ord.size() || ord[s + l] != all[j][l]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) w[(int)ord.size()]++;
    }
    for (int i = 0; i < k; ++i) {
        if (all_s[i].empty()) w[1]++;
    }
    vector <ll> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (auto j : w) {
            if (i + j.first <= m) {
                dp[i + j.first] += dp[i] * j.second;
                dp[i + j.first] %= mod;
            }
        }
    }
    cout << dp[m];
}

/*

 */