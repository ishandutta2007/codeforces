#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> a;
vector <int> used, ord;

void dfs(int v) {
    used[v] = 1;
    for (int i : a[v]) {
        if (used[i] == 0) dfs(i);
        if (used[i] == 1) {
            cout << -1;
            exit(0);
        }
    }
    used[v] = 2;
    ord.push_back(v);
}

signed main() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
    }
    used.resize(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs(i);
    }
    reverse(ord.begin(), ord.end());
    vector <int> dp(n, n);
    vector <bool> ans(n), ans1(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        dp[ord[i]] = min(dp[ord[i]], ord[i]);
        for (int j : a[ord[i]]) {
            dp[j] = min(dp[ord[i]], dp[j]);
        }
        if (dp[ord[i]] == ord[i]) {
            ans[ord[i]] = true;
        }
    }
    vector <int> dp1(n, n);
    for (int i = n - 1; i >= 0; --i) {
        dp1[ord[i]] = min(dp1[ord[i]], ord[i]);
        for (int j : a[ord[i]]) {
            dp1[ord[i]] = min(dp1[ord[i]], dp1[j]);
        }
        if (dp1[ord[i]] == ord[i]) {
            ans1[ord[i]] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] && ans1[i]) {
            ++res;
        }
        else {
            ans[i] = false;
        }
    }
    cout << res << "\n";
    for (int i = 0; i < n; ++i) {
        if (ans[i]) cout << "A";
        else cout << "E";
    }
}