#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
const int MAXV = 1e7 + 10;
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<int> mind(MAXV, -1), pr;
    for (int i = 2; i < MAXV; ++i) {
        if (mind[i] == -1) {
            mind[i] = i;
            pr.push_back(i);
        }
        for (int j: pr) {
            if (j > mind[i] || j * i >= MAXV) break;
            mind[i * j] = j;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        map<vector<int>, int> d;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            vector<int> all;
            while (x > 1) {
                int md = mind[x], c = 0;
                while (x % md == 0) {
                    c ^= 1;
                    x /= md;
                }
                if (c) all.push_back(md);
            }
            if (d.count(all)) a.push_back(d[all]);
            else {
                a.push_back(cnt);
                d[all] = cnt++;
            }
        }
        vector<vector<int>> bad(n);
        vector<int> last(n, -1);
        last[a[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            bad[i] = bad[i + 1];
            int x = -1;
            if (last[a[i]] != -1) {
                x = last[a[i]];
            }
            last[a[i]] = i;
            if (x == -1) continue;
            bad[i].insert(upper_bound(bad[i].begin(), bad[i].end(), x), x);
            if ((int) bad[i].size() == k + 2) bad[i].pop_back();
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= k; ++c) {
                int val = dp[i][c];
                if (val == INF) continue;
                for (int pl = 0; pl + c <= k && (int) bad[i].size() >= pl; ++pl) {
                    int j;
                    if (pl == (int) bad[i].size()) j = n;
                    else j = bad[i][pl];
                    dp[j][pl + c] = min(dp[j][pl + c], val + 1);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, dp[n][i]);
        }
        cout << ans << "\n";
    }
}

/*

 */