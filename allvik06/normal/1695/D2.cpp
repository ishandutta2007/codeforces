#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <vector <int>> g;
vector <int> dp, cntl, gl, pr;

void dfs(int v, int p) {
    int cnt0 = 0, sum = 0;
    for (int i : g[v]) {
        if (i == p) continue;
        dfs(i, v);
        sum += dp[i];
        if (!dp[i]) ++cnt0;
    }
    dp[v] = sum + max(0, cnt0 - 1);
}

void calcl(int v, int p) {
    int cnt = 0;
    for (int i : g[v]) {
        if (i == p) continue;
        ++cnt;
        pr[i] = v;
        gl[i] = gl[v] + 1;
        calcl(i, v);
        cntl[v] += cntl[i];
    }
    if (cnt == 0) cntl[v] = 1;
}

int findl(int v, int p) {
    for (int i : g[v]) {
        if (i == p) continue;
        return findl(i, v);
    }
    return v;
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
        int n;
        cin >> n;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        g.assign(n, {});
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y; --x; --y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        dp.assign(n, 0);
        dfs(0, -1);
        if (dp[0] == 0) {
            cout << "1\n";
            continue;
        }
        cntl.assign(n, 0);
        gl.assign(n, 0);
        pr.assign(n, -1);
        calcl(0, -1);
        int flex = -1;
        for (int i = 0; i < n; ++i) {
            if (cntl[i] > 1 && (flex == -1 || gl[flex] < gl[i])) flex = i;
        }
        int root1 = -1, root2 = -1;
        for (int i : g[flex]) {
            if (i == pr[flex]) continue;
            if (root1 == -1) root1 = findl(i, flex);
            else {
                root2 = findl(i, flex);
                break;
            }
        }
        dfs(root1, -1);
        int ans = dp[root1] + 1;
        dfs(root2, -1);
        cout << min(ans, dp[root2] + 1) << "\n";
    }
}