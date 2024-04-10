#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)400200;
const ll inf = (1ll<<50);
int n, m;
int d[26][26];
ll dp[1<<16];
ll get(int mask) {
    if(mask == 0) return 0;
    ll &res = dp[mask];
    if(res != -1) return res;
    res = inf;
    int cur = 0;
    while(!(mask & (1<<cur))) cur++;
    for(int i = cur + 1; i < n; i++) {
        if(mask & (1<<i)) {
            res = min(res, get(mask^(1<<i) ^ (1<<cur)) + d[cur+1][i+1]);
        }
    }
    return res;
}
int was[maxn];
vector<int> g[maxn];
int used[maxn];
void dfs(int v) {
    used[v] = 1;
    for(int to: g[v]) {
        if(!used[to]) dfs(to);
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = 1<<29;
        }
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    int mask = 0;
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
        d[y][x] = min(d[y][x], z);
        ans += z;
        mask ^= (1<<(x-1));
        mask ^= (1<<(y-1));
        was[x] = 1;
        was[y] = 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(!used[i] && was[i]) {
            cout << -1 << "\n";
            return;
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cout << ans + get(mask) << "\n";

}
int main() {

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}