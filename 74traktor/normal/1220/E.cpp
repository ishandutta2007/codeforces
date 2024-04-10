#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
int const maxn = 2e5 + 5;
vector < int > g[maxn];
vector < int > G[maxn];
int a[maxn];
int b[maxn];
int tin[maxn];
int up[maxn];
int dp[maxn][2];
int used[maxn];
int gett[maxn];
int sz[maxn];
int cur;
set < pair < int, int > > Q;
int numb;
int F[maxn];
int inf = 1e18;
 
void dfs2(int v, int p) {
    numb--;
    //cout << v << " " << p << endl;
    dp[v][1] = -1 * inf, dp[v][0] = -1 * inf;
    int child = 0, sum = 0, imax = 0, summa = 0;
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs2(u, v);
        //F[v] += F[u];
        if (F[u] > 1) sum += dp[u][1], summa += F[u];
        else imax = max(imax, dp[u][0]);
        child++;
    }
    if (child == 0) {
        F[v] = sz[v];
        dp[v][0] = b[v], dp[v][1] = b[v];
    }
    else {
        dp[v][0] = max(dp[v][0], sum + imax);
        //if (v == 3) cout << sum << " " << imax << endl;
        for (auto u : G[v]) {
            if (u != p) {
                if (F[u] > 1) dp[v][0] = max(dp[v][0], sum - dp[u][1] + dp[u][0]);
            }
        }
        //if (v == 3) cout << dp[v][0] << endl;
        dp[v][0] += b[v];
        sum = 0;
        for (auto u : G[v]) {
            if (u == p) continue;
            if (F[u] > 1) sum += dp[u][1];
        }
        F[v]= summa + sz[v];
        dp[v][1] = sum + b[v];
    }
    //cout << v << " " << sz[v] << " " << b[v] << " " << dp[v][0] << " " << dp[v][1] << '\n';
}
 
void dfs1(int v) {
    //cout << v << " " << a[v] << " " << b[numb] << " " << numb << endl;
    used[v] = 2;
    sz[numb]++;
    b[numb] += a[v];
    gett[v] = numb;
    for (auto u : g[v]) if (Q.find({min(u, v), max(u, v)}) == Q.end() && used[u] == 1) dfs1(u);
}
 
void dfs(int v, int p) {
    tin[v] = cur, up[v] = cur, used[v] = 1, cur++;
    for (auto u : g[v]) {
        if (u == p) continue;
        if (used[u] == 1) up[v] = min(up[v], tin[u]);
        else {
            dfs(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] > tin[v]) Q.insert({min(u, v), max(u, v)});
        }
    }
}
 
main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) if (used[i] == 1) numb++, dfs1(i);
    //for (int i = 1; i <= numb; ++i) cout << b[i] << " ";
    //cout << '\n';
    int start;
    cin >> start;
    for (auto key : Q) {
        //cout << gett[key.first] << " " << gett[key.second] << '\n';
        G[gett[key.first]].push_back(gett[key.second]);
        G[gett[key.second]].push_back(gett[key.first]);
    }
    //for (auto key : Q) cout << key.first << " " << key.second << '\n';
    //for (int i = 1; i <= numb; ++i) cout << gett[i] << " ";
    //cout << '\n';
    //cout << gett[start] << '\n';
    dfs2(gett[start], 0);
    if (numb != 0) {
        cout << 1 / 0 << endl;
        return 0;
    }
    cout << max(dp[gett[start]][0], dp[gett[start]][1]);
    return 0;
}