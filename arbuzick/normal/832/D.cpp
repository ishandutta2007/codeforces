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
int tin[maxn], tout[maxn], d[maxn];
int t = 0;
void dfs(int v, int pr, int d1) {
    tin[v] = t;
    d[v] = d1;
    t++;
    go[0][v] = pr;
    for (auto u: g[v])
        if (u != pr)
            dfs(u, v, d1+1);
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
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x, x--;
        g[i].pb(x);
        g[x].pb(i);
    }
    dfs(0, 0, 0);
    for (int i = 1; i < l; ++i)
        for (int j = 0; j < n; ++j)
            go[i][j] = go[i-1][go[i-1][j]];
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        int ans = 0;
        for (auto f: {a, b, c}) {
            int s, t;
            if (f == a)
                s = b;
            else
                s = a;
            t = a+b+c-f-s;
            int ans1 = 1;
            if (f == lca(s, f)) {
                ans1 += d[lca(s, t)]-d[f];
            } else if (s == lca(s, f)) {
                ans1 += d[f]-max(d[s], d[lca(f, t)]);
            } else if (d[lca(s, t)] <= d[lca(s, f)]) {
                ans1 += max(0LL, d[f]-max(d[lca(s, f)], d[lca(f, t)]));
            } else {
                ans1 += (d[f]-d[lca(s, f)]+d[lca(s, t)]-d[lca(s, f)]);
            }
            ans = max(ans, ans1);
        }
        cout << ans << '\n';
    }
    return 0;
}