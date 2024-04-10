#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

const int LOG = 20;

vector<pii> g[N];
vector<int> G[N];
int n;
ll depth[N];

int timer, tin[N], tout[N];
int up[N][LOG];

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i < LOG; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto to: g[v]) {
        if (to.f == p)
            continue;
        G[v].pb(to.f);
        depth[to.f] = depth[v] + to.s;
        dfs(to.f, v);
    }
    tout[v] = timer;
}

bool upper(int v, int u) {
    return tin[v] <= tin[u] && tin[u] <= tout[v];
}

int lca(int v, int u) {
    if (upper(v, u))
        return v;
    if (upper(u, v))
        return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (!upper(up[v][i], u))
            v = up[v][i];
    return up[v][0];
}

ll dist(int v, int u) {
    return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}

ll dist(pii x) {
    return dist(x.f, x.s);
}

void chmx(pair<pii, ll> &a, pair<pii, ll> b) {
    if (b.s > a.s)
        a = b;
}

pii kek(pii a, pii b) {
    pair<pii, ll> c = {a, dist(a)};
    chmx(c, {b, dist(b)});
    chmx(c, {{a.f, b.f}, dist(a.f, b.f)});
    chmx(c, {{a.f, b.s}, dist(a.f, b.s)});
    chmx(c, {{a.s, b.f}, dist(a.s, b.f)});
    chmx(c, {{a.s, b.s}, dist(a.s, b.s)});
    return c.f;
}

pii dp[N], dp2[N], pre[N], suf[N];

ll ans;

void dfs1(int v) {
    dp[v] = {v, v};
    for (auto to: G[v]) {
        dfs1(to);
        dp[v] = kek(dp[v], dp[to]);
    }
}

void dfs2(int v) {
    for (int i = 0; i < G[v].size(); i++) {
        if (i)
            pre[i] = pre[i - 1];
        else
            pre[i] = {v, v};
        pre[i] = kek(pre[i], dp[G[v][i]]);
    }
    for (int i = G[v].size() - 1; i >= 0; i--) {
        if (i + 1 < G[v].size())
            suf[i] = suf[i + 1];
        else
            suf[i] = {v, v};
        suf[i] = kek(suf[i], dp[G[v][i]]);
    }
    for (int i = 0; i < G[v].size(); i++) {
        pii x = {v, v};
        if (i - 1 >= 0)
            x = kek(x, pre[i - 1]);
        if (i + 1 < G[v].size())
            x = kek(x, suf[i + 1]);
        if (v != 1)
            x = kek(x, dp2[v]);
        dp2[G[v][i]] = x;
    }
    vector<ll> lol;
    lol.pb(0);
    lol.pb(0);
    lol.pb(0);
    lol.pb(0);
    for (auto to: G[v])
        lol.pb(max(dist(v, dp[to].f), dist(v, dp[to].s)));
    if(v != 1)
        lol.pb(max(dist(v, dp2[v].f), dist(v, dp2[v].s)));
    sort(lol.begin(), lol.end());
    reverse(lol.begin(), lol.end());
    ans = max(ans, lol[0] + lol[1] + lol[2] + lol[3]);

    for (auto to: G[v]) {
        ans = max(ans, dist(dp2[to]) + dist(dp[to]) + dist(v, to) * 2);
        dfs2(to);
    }
}

void solve() {
    cin >> n;
    ll s = 0;
    for (int i = 1; i < n; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        g[v].pb({u, w});
        g[u].pb({v, w});
        s += w;
    }
    dfs(1, 1);
    dfs1(1);
    dfs2(1);
    cout << 2 * s - ans << endl;
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}