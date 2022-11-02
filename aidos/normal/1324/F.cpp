#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int c[maxn];
vector<int> g[maxn];
int dp[maxn];
int ans[maxn];
int used[maxn];
void dfs(int v, int p = -1) {
    if(c[v]) dp[v] = 1;
    else dp[v] = -1;
    for(const int &to: g[v]) {
        if(to != p) {
            dfs(to, v);
            if(dp[to] > 0) {
                dp[v] += dp[to];
                used[to] = 1;
            }
        }
    }
}
void dfs2(int v, int p = -1, int val = 0) {
    ans[v] = dp[v] + val;
    for(const int &to: g[v]) {
        if(to != p) {
            int cur = val + dp[v];
            if(used[to]) cur -= dp[to];
            dfs2(to, v, max(cur, 0));

        }
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1);
    dfs2(1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}