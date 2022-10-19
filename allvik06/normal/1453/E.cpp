#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> g;
vector <int> dp;

void dfs(int v, int p, int kol) {
    if (g[v].size() == 1 && v != 0) {
        dp[v] = 0;
        return;
    }
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v, kol);
            if (dp[i] == -1) {
                dp[v] = -1;
                return;
            }
        }
    }
    int fmax = -1, smax = -1, minn = 1000000;
    for (int i : g[v]) {
        if (i != p) {
            minn = min(minn, dp[i]);
            if (dp[i] > fmax) {
                smax = fmax;
                fmax = dp[i];
            } else if (dp[i] > smax) {
                smax = dp[i];
            }
        }
    }
    if (smax == -1) {
        if (fmax + 1 <= kol) {
            dp[v] = fmax + 1;
        } else dp[v] = -1;
        return;
    }
    if (fmax + 2 <= kol) {
        dp[v] = minn + 1;
        return;
    } else if (fmax + 1 == kol) {
        if (smax == fmax) dp[v] = -1;
        else dp[v] = fmax + 1;
        return;
    } else {
        dp[v] = -1;
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.assign(n, {});
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            g[x - 1].push_back(y - 1);
            g[y - 1].push_back(x - 1);
        }
        int l = 0, r = n + 1;
        dp.assign(n, -1);
        while (r - l > 1) {
            int m = (l + r) / 2;
            dfs(0, -1, m);
            if (dp[0] != -1) r = m;
            else l = m;
        }
        cout << r << "\n";
    }
}