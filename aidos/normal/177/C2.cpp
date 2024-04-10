#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
vector<int> g[maxn];
int u[maxn];
int cnt[maxn];
int n, m;
int bad[maxn];
void dfs(int v, int c) {
    u[v] = c;
    cnt[c]++;
    for(const int &to: g[v]) {
        if(u[to] == 0) dfs(to, c);
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(u[i] == 0) {
            dfs(i,i);
        }else bad[i] = 1;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if(u[x] == u[y]) bad[u[x]] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(!bad[i]) ans = max(ans, cnt[i]);
    cout << ans << "\n";
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