#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int c[4][maxn];
vector<int> g[maxn];
int col[maxn];
ll dfs(int v, int p, int c1, int c2) {
    ll cur = c[c1][v];
    col[v] = c1;
    for(const int &to: g[v]) {
        if(to == p) continue;
        cur += dfs(to, v, 6-c2-c1, c1);
    }
    return cur;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++) cin >> c[i][j];
    }
    for(int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        if(g[u].size() > 2 || g[v].size() > 2) {
            cout << -1 << "\n";
            return;
        }
    }
    if(n == 1) {
        int mi = min(c[1][1], min(c[2][1], c[3][1]));
        cout << mi << "\n";
        for(int i=1; i <= 3; i++) {
            if(c[i][1] == mi) {
                cout << i << "\n";
                return;
            }
        }
    }
    int v1 = 0, v2 = 0;
    ll ans = 1ll<<50;
    int v = g[1][0];
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(i == j) continue;

            ll cur = dfs(1, v, i, j) + dfs(v, 1, j, i);
            if(cur < ans) {
                ans = cur;
                v1 = i;
                v2 = j;
            }
        }
    }
    dfs(1, v, v1, v2);
    dfs(v, 1, v2, v1);
    cout << ans << "\n";
    for(int i = 1; i <= n; i++) cout << col[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}