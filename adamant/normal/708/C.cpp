#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 42;

vector<int> g[maxn];
int sz[maxn];
int n;

int dfs(int v = 0, int p = 0)
{
    sz[v] = 1;
    int ret = v;
    for(auto u: g[v])
    {
        if(u == p)
            continue;
        int t = dfs(u, v);
        sz[v] += sz[u];
        if(2 * sz[u] > n)
            ret = t;
    }
    return ret;
}

int in[maxn], out[maxn];
int t = 0;

int upd[maxn], pp[maxn];

void dfs2(int v, int p)
{
    in[v] = t++;
    sz[v] = 1;
    for(auto u: g[v])
        if(u != p)
        {
            //cout << v << "-->" << u << endl;
            if(v == p)
                pp[u] = u;
            else
                pp[u] = pp[v];
            dfs2(u, v);
            sz[v] += sz[u];
        }
    //cout << v << ' '  << p << ' ' << sz[v] << endl;
    upd[in[v]] = sz[v];
    out[v] = t;
}

vector<int> st[4 * maxn];

void build(int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        st[v] = {upd[l]};
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    merge(begin(st[2 * v]), end(st[2 * v]), begin(st[2 * v + 1]), end(st[2 * v + 1]), back_inserter(st[v]));
}

int lwb(int a, int b, int c, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return maxn;
    if(r <= a || b <= l)
    {
        auto it = lower_bound(begin(st[v]), end(st[v]), c);
        if(it == end(st[v]))
            return maxn;
        else
            return *it;
    }
    int m = (l + r) / 2;
    return min(lwb(a, b, c, 2 * v, l, m), lwb(a, b, c, 2 * v + 1, m, r));
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = dfs();
    int mx = n - sz[cnt];
    int cnts = 0;
    for(int i = 0; i < n; i++)
    {
        int v = i;
        int mx = n - sz[v];
        for(auto u: g[v])
            if(sz[u] < sz[v])
                mx = max(mx, sz[u]);
        cnts += 2 * mx <= n;
    }
    if(cnts == 2)
    {
        for(int i = 0; i < n; i++)
            cout << 1 << ' ';
        return 0;
    }
    dfs2(cnt, cnt);
    //cout << cnt << endl;
    build();
    for(int i = 0; i < n; i++)
    {
        //cout << sz[i] << " ";
        int v = i;
        //cout << mn << ' ' << lwb(in[v], out[v], (n - sz[v]) - n / 2) << "\n";
        if(2 * min(lwb(in[pp[v]], out[pp[v]], (n - sz[v]) - n / 2), n - sz[pp[v]]) <= n)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
    return 0;
}