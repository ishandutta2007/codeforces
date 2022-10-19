#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int maxn = 100005, l = 17;
int go[l][maxn];
vector<int> g[maxn];
int tin[maxn], tout[maxn], d[maxn], sz[maxn];
int t = 0;
void dfs(int v, int pr, int d1) {
    tin[v] = t;
    d[v] = d1;
    t++;
    sz[v] = 1;
    go[0][v] = pr;
    for (auto u: g[v])
        if (u != pr)
            dfs(u, v, d1+1), sz[v] += sz[u];
    tout[v] = t;
    t++;
}
int lca(int a, int b) {
    if (tin[a] <= tin[b] && tout[b] <= tout[a])
        return a;
    if (tin[b] <= tin[a] && tout[a] <= tout[b])
        return b;
    int v = a;
    for (int i = l-1; i >= 0; --i) {
        if (!(tin[go[i][v]] <= tin[b] && tout[b] <= tout[go[i][v]]))
            v = go[i][v];
    }
    v = go[0][v];
    return v;
}
int solve(int v, int k){
    for(int i = l-1; i >= 0; --i){
        if((1 << i) <= k)
            return solve(go[i][v], k-(1 << i));
    }
    return v;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, 0, 0);
    for (int i = 1; i < l; ++i)
        for (int j = 0; j < n; ++j)
            go[i][j] = go[i-1][go[i-1][j]];
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b, a--, b--;
        if (a == b) {
            cout << n << '\n';
            continue;
        }
        if ((d[a]+d[b])%2) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        if (d[a]-d[lca(a, b)] == d[b]-d[lca(a, b)]) {
            ans += n;
            ans -= sz[solve(a, d[a]-d[lca(a, b)]-1)];
            ans -= sz[solve(b, d[b]-d[lca(a, b)]-1)];
        } else {
            if (d[a] < d[b])
                swap(a, b);
            int v = solve(a, (d[a]-d[lca(a, b)]+d[b]-d[lca(a, b)])/2);
            ans += sz[v];
            ans -= sz[solve(a, d[a]-d[v]-1)];
        }
        cout << ans << '\n';
    }
    return 0;
}