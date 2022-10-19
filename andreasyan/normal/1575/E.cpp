#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, M = 1000000007;

int n, k;
int a[N];

vector<int> g[N], gc[N];

bool c[N];

int q[N];
void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p, int xx)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        if (q[h] > q[xx] / 2)
            return dfsc(h, x, xx);
    }
    return x;
}

int s[N];
void dfs1(int x, int p, int gg)
{
    if (x == p)
        s[x] = a[x];
    else
        s[x] = (s[p] + a[x]) % M;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        if (gg != -1 && gc[x][i] != gg)
            q[h] = q[x] + 1;
        else
            q[h] = q[x];
        dfs1(h, x, gc[x][i]);
    }
}

vector<int> v;
void dfs2(int x, int p)
{
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs2(h, x);
    }
}

pair<int, int> t[2][N * 4];

pair<int, int> mer(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M, a.se + b.se);
}

void ubd(pair<int, int> t[], int tl, int tr, int x, int yf, int ys, int pos)
{
    if (tl == tr)
    {
        t[pos].fi = (t[pos].fi + yf) % M;
        t[pos].se += ys;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(t, tl, m, x, yf, ys, pos * 2);
    else
        ubd(t, m + 1, tr, x, yf, ys, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, int> qry(pair<int, int> t[], int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(t, tl, m, l, min(m, r), pos * 2),
            qry(t, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int ans;
void solvv(int r)
{
    q[r] = 0;
    dfs1(r, r, -1);

    ans = (ans + a[r]) % M;
    for (int i = 0; i < g[r].size(); ++i)
    {
        int x = g[r][i];

        if (c[x])
            continue;

        int xc = gc[r][i];
        v.clear();
        dfs2(x, r);

        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            if (q[x] > k)
                continue;

            ans = (ans + s[x]) % M;

            pair<int, int> u = qry(t[xc], 0, k, 0, k - q[x], 1);
            ans = (ans + u.fi) % M;
            ans = (ans + u.se * 1LL * (s[x] - a[r])) % M;

            u = qry(t[(xc ^ 1)], 0, k, 0, k - q[x] - 1, 1);
            ans = (ans + u.fi) % M;
            ans = (ans + u.se * 1LL * (s[x] - a[r])) % M;
        }
        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            if (q[x] > k)
                continue;
            ubd(t[xc], 0, k, q[x], s[x], 1, 1);
        }
    }

    for (int i = 0; i < g[r].size(); ++i)
    {
        int x = g[r][i];

        if (c[x])
            continue;

        int xc = gc[r][i];
        v.clear();
        dfs2(x, r);
        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            if (q[x] > k)
                continue;
            ubd(t[xc], 0, k, q[x], -s[x], -1, 1);
        }
    }
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(y);
        g[y].push_back(x);
        gc[x].push_back(z);
        gc[y].push_back(z);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        dfs0(x, x);
        x = dfsc(x, x, x);

        solvv(x);

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (c[h])
                continue;
            q.push(h);
        }
        c[x] = true;
    }

    ans = (ans + M) % M;
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}