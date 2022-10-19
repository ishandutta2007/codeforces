#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 200005;

vector<int> g[N];
int p[N];
vector<int> deps[N];
int dp[N];
int a[N];

void dfs(int u, int dep) {
    deps[dep].push_back(u);
    for (int e : g[u]) {
        dfs(e, dep + 1);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            cin >> p[i];
            g[p[i]].push_back(i);
        }       
        for (int i = 2; i <= n; i++) cin >> a[i];
        dfs(1, 0);
        dp[1] = 0;
        for (int i = 1; i < N; i++) {
            if (deps[i].empty()) break;
            sort(deps[i].begin(), deps[i].end(), [&](int u, int v) {
                return a[u] < a[v];
            });
            {
                int mx = -1e18;
                for (int j = 0; j < deps[i].size(); j++) {
                    int u = deps[i][j];
                    dp[u] = max(dp[u], a[u] + max(mx, dp[p[u]] - a[deps[i][0]]));
                    mx = max(mx, dp[p[u]] - a[u]);
                }
            }
            {
                int mx = -1e18;
                for (int j = deps[i].size() - 1; j >= 0; j--) {
                    int u = deps[i][j];
                    dp[u] = max(dp[u], max(mx, dp[p[u]] + a[deps[i].back()]) - a[u]);
                    mx = max(mx, dp[p[u]] + a[u]);
                }
            }
        }
        int ans = -1e18;
        for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        cout << ans << '\n';
        // for (int i = 1; i <= n; i++) {
        //     cout << i << ' ' << dp[i] << endl;
        // }
        {
            for (int i = 1; i <= n; i++) {
                g[i].clear();
                deps[i].clear();
                dp[i] = -1e18;
            }
        }
    }

    return 0;
}