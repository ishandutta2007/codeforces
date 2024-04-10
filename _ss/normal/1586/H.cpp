#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 10;
const int lgn = 17;
struct edge {int u, v, c, t;};
edge E[N];
pii Q[N], ans[N];
vector<pii> G[N];
int n, q, root[N], mn_pos[N], mx_pos[N], mx_val[N], e[N], pos[N], st[N], P[N];
vi S[N];

void merg(int u, int v)
{
    if (S[u].size() < S[v].size()) swap(u, v);
    for (int x : S[v]) S[u].eb(x), root[x] = u;
    S[v].clear();
    if (mx_val[v] > mx_val[u])
    {
        mx_val[u] = mx_val[v];
        mn_pos[u] = mn_pos[v];
        mx_pos[u] = mx_pos[v];
    }
    else if (mx_val[v] == mx_val[u])
    {
        mn_pos[u] = min(mn_pos[u], mn_pos[v]);
        mx_pos[u] = max(mx_pos[u], mx_pos[v]);
    }
}

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        S[i] = {i};
        root[i] = i;
        mn_pos[i] = mx_pos[i] = pos[i];
        mx_val[i] = e[i];
    }
}

int spr[20][N], h[N], spr_mx[20][N];

void dfs(int u)
{
    for (int i = 1; i <= lgn; ++i)
    {
        spr[i][u] = spr[i - 1][spr[i - 1][u]];
        spr_mx[i][u] = max(spr_mx[i - 1][u], spr_mx[i - 1][spr[i - 1][u]]);
    }
    for (pii v : G[u])
        if (v.fi != spr[0][u])
        {
            spr[0][v.fi] = u;
            spr_mx[0][v.fi] = v.se;
            h[v.fi] = h[u] + 1;
            dfs(v.fi);
        }
}

pii find_anc(int u, int h)
{
    int res = 0;
    for (int i = 0; h; h >>= 1, ++i)
        if (h & 1) res = max(res, spr_mx[i][u]), u = spr[i][u];
    return mp(u, res);
}

int max_e(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int res = 0;
    pii tmp = find_anc(u, h[u] - h[v]);
    u = tmp.fi;
    res = max(res, tmp.se);
    int k = lgn;
    while (u != v)
    {
        while (k && spr[k][u] == spr[k][v]) k--;
        res = max({res, spr_mx[k][u], spr_mx[k][v]});
        u = spr[k][u];
        v = spr[k][v];
    }
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> e[i];
    for (int i = 1, u, v, c, t; i < n; ++i)
    {
        cin >> u >> v >> c >> t;
        E[i] = {u, v, c, t};
        G[u].eb(v, t);
        G[v].eb(u, t);
    }
    for (int i = 1; i <= q; ++i) cin >> Q[i].fi >> Q[i].se;
    sort(E + 1, E + n, [](const edge &e1, const edge & e2) { return e1.t < e2.t;});
    init();
    for (int i = 1; i < n; ++i) merg(root[E[i].u], root[E[i].v]);
    for (int i = 0; i < n; ++i)
    {
        int u = S[root[1]][i];
        st[i] = u;
        pos[u] = i;
    }
    sort(E + 1, E + n, [](const edge &e1, const edge &e2) { return e1.c > e2.c;});
    init();
    for (int i = 1; i <= q; ++i) P[i] = i;
    sort(P + 1, P + q + 1, [](const int &id1, const int &id2) { return Q[id1].fi > Q[id2].fi;});
    dfs(1);
    int j = 1;
    for (int i = 1; i <= q; ++i)
    {
        int c = Q[P[i]].fi, x = Q[P[i]].se;
        while (j < n && E[j].c >= c) merg(root[E[j].u], root[E[j].v]), j++;
        int u = st[mn_pos[root[x]]], v = st[mx_pos[root[x]]];
        ans[P[i]] = mp(mx_val[root[x]], max(max_e(x, u), max_e(x, v)));
    }
    for (int i = 1; i <= q; ++i) cout << ans[i].fi << " " << ans[i].se << "\n";
    return 0;
}