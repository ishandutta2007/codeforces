#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

int dp[NMAX];
vector<int> G[NMAX];
int deg[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x < y) swap(x, y);
        G[x].push_back(y);
        deg[x]++;
        deg[y]++;
    }
    
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int p: G[i]) {
            dp[i] = max(dp[i], dp[p] + 1);
        }
        ans = max(ans, (int64_t) dp[i] * deg[i]);
    }
    
    cout << ans << '\n';
}