#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
vector <vector <int>> g;
vector <int> c, sz, ans;
vector <bool> dp;
int cnt = 0;

void dfs(int v, int p) {
    sz[v] = c[v];
    bool f = false;
    for (int i : g[v]) {
        if (i == p) continue;
        if (c[i] == 1) f = true;
        dfs(i, v);
        sz[v] += sz[i];
        dp[v] = (dp[v] || dp[i]);
    }
    if (f && sz[v] > 1) dp[v] = true;
}

void dfs1(int v, int p, bool ok = false) {
    bool me = ok || dp[v] || c[v];
    int cc = 0, cnt1 = 0;
    for (int i : g[v]) {
        me = (me || c[i]);
        cc += c[i];
        if (i != p) cnt1 += dp[i];
    }
    ans[v] = me;
    for (int i : g[v]) {
        if (i == p) continue;
        bool new_ok = ok;
        if (dp[i]) --cnt1;
        if (c[i]) --cc;
        if (cnt1 || (cc && cnt - sz[i] > 1)) new_ok = true;
        dfs1(i, v, new_ok);
        if (dp[i]) ++cnt1;
        if (c[i]) ++cc;
    }
}
signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    c.resize(n);
    g.resize(n);
    dp.resize(n);
    sz.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        cnt += c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    dfs1(0, -1);
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
}

/*

 */