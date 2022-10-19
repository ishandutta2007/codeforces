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
#define int long long
const int mod = 998244353;
vector <vector <int>> g;
vector <int> dp;

bool dfs(int v, int p, int k) {
    for (int i : g[v]) {
        if (i != p) {
            if (!dfs(i, v, k)) return false;
        }
    }
    if (dp[v] % k == 0) {
        if (p != -1) {
            ++dp[p];
        }
        return true;
    } else {
        ++dp[v];
        return dp[v] % k == 0;
    }
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
        g.assign(n, {});
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> flex(n + 1);
        dp.assign(n, 0);
        flex[1] = 1;
        for (int i = 0; i < n - 1; ++i) {
            flex[1] = (flex[1] * 2) % mod;
        }
        for (int i = 2; i <= n - 1; ++i) {
            if ((n - 1) % i == 0) {
                flex[i] = dfs(0, -1, i);
                for (int j = 0; j < n; ++j) dp[j] = 0;
            }
        }
        for (int i = n; i > 0; --i) {
            for (int j = 2 * i; j <= n; j += i) {
                flex[i] = (flex[i] - flex[j] + mod) % mod;
            }
        }
        for (int i = 1; i <= n; ++i) cout << flex[i] << " ";
        cout << "\n";
    }
}

/*

 */