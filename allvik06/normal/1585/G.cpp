#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
const int INF = 1e9;
vector <vector <int>> g;
vector <int> gl, mn;

void calc_info(int v) {
    if (g[v].empty()) {
        mn[v] = gl[v];
    }
    for (int i : g[v]) {
        gl[i] = gl[v] + 1;
        calc_info(i);
        mn[v] = min(mn[v], mn[i]);
    }
}
vector <vector <int>> dp;
vector <set <int>> all;
vector <map <int, int>> cnt;


void calc_dp(int v) {
    if (g[v].empty()) {
        dp[v].push_back(0);
        dp[v].push_back(1);
        all[v].insert(2);
        ++cnt[v][1];
        ++cnt[v][0];
        return;
    }
    int mx = g[v][0];
    for (int i : g[v]) {
        calc_dp(i);
        if (gl[i] > gl[mx]) mx = i;
    }
    dp[v].swap(dp[mx]);
    all[v].swap(all[mx]);
    cnt[v].swap(cnt[mx]);
    int c = (mn[v] + 1) - (gl[v] + 1) + 1;
    int prev_c = (mn[mx] + 1) - (gl[v] + 1) + 1;
    while (prev_c > c) {
        int ind = (int)dp[v].size() - prev_c;
        prev_c--;
        --cnt[v][dp[v][ind]];
        if (cnt[v][dp[v][ind]] == 0) all[v].insert(dp[v][ind]);
    }
    for (int i : g[v]) {
        if (i == mx) continue;
        for (int j = gl[v] + 1; j <= mn[v] + 1; ++j) {
            int ind1 = (int)dp[i].size() - (j - gl[v]);
            int ind2 = (int)dp[v].size() - (j - gl[v]);
            if (ind1 < 0) break;
            --cnt[v][dp[v][ind2]];
            if (cnt[v][dp[v][ind2]] == 0) all[v].insert(dp[v][ind2]);
            dp[v][ind2] ^= dp[i][ind1];
            ++cnt[v][dp[v][ind2]];
            if (cnt[v][dp[v][ind2]] == 1) all[v].erase(dp[v][ind2]);
        }
    }
    dp[v].push_back(*all[v].begin());
    all[v].erase(all[v].begin());
    ++cnt[v][dp[v].back()];
    int x = mn[v] - gl[v] + 2;
    if (cnt[v][x] == 0) all[v].insert(x);
}

void solve() {
    int n;
    cin >> n;
    g.assign(n, {});
    vector <int> roots;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x; --x;
        if (x == -1) roots.push_back(i);
        else g[x].push_back(i);
    }
    gl.assign(n, 0);
    mn.assign(n, INF);
    for (int i : roots) {
        calc_info(i);
    }
    dp.assign(n, {});
    all.assign(n, {});
    cnt.assign(n, {});
    int x = 0;
    for (int i : roots) {
        calc_dp(i);
        x ^= dp[i].back();
    }
    if (x) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */