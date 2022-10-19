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
const int N = 150005;
const ll INF = 1000000009000000009;

int n;
vector<int> g[N];
int a[N];

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

ll ans;

int d[N];
ll s[N];
ll d1[N], d2[N];
void dfs1(int x, int p)
{
    if (x == p)
    {
        d[x] = 1;
        s[x] = a[x];
        d1[x] = d2[x] = a[x];
    }
    else
    {
        d[x] = d[p] + 1;
        s[x] = s[p] + a[x];
        d1[x] = d1[p] + d[x] * 1LL * a[x];
        d2[x] = d2[p] + s[x];
    }

    ans = max(ans, d1[x]);
    ans = max(ans, d2[x]);

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs1(h, x);
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

struct ban
{
    ll b, k;
    ban()
    {
        b = -INF;
        k = 0;
    }
    ban(ll b, ll k)
    {
        this->b = b;
        this->k = k;
    }
    ll yat(ll x)
    {
        return b + k * x;
    }
};

ban t[N * 4];

void ubd(int tl, int tr, ban u, int pos)
{
    int m = (tl + tr) / 2;
    if (u.yat(m) > t[pos].yat(m))
        swap(u, t[pos]);
    if (tl == tr)
        return;

    if (u.yat(tl) > t[pos].yat(tl))
        ubd(tl, m, u, pos * 2);
    else
        ubd(m + 1, tr, u, pos * 2 + 1);
}

ll qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos].yat(x);
    int m = (tl + tr) / 2;
    if (x <= m)
        return max(qry(tl, m, x, pos * 2),
                   t[pos].yat(x));
    return max(qry(m + 1, tr, x, pos * 2 + 1),
                t[pos].yat(x));
}

void clr(int tl, int tr, int pos)
{
    if (t[pos].b == -INF)
        return;
    t[pos].b = -INF;
    t[pos].k = 0;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    clr(tl, m, pos * 2);
    clr(m + 1, tr, pos * 2 + 1);
}

void solvv(int r)
{
    dfs1(r, r);

    clr(1, n, 1);
    for (int i = 0; i < g[r].size(); ++i)
    {
        int x = g[r][i];
        if (c[x])
            continue;

        v.clear();
        dfs2(x, r);

        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            ans = max(ans, d2[x] + qry(1, n, d[x], 1));
        }
        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            ubd(1, n, ban(d1[x] - s[x], s[x] - a[r]), 1);
        }
    }

    clr(1, n, 1);
    for (int i = sz(g[r]) - 1; i >= 0; --i)
    {
        int x = g[r][i];
        if (c[x])
            continue;

        v.clear();
        dfs2(x, r);

        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            ans = max(ans, d2[x] + qry(1, n, d[x], 1));
        }
        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            ubd(1, n, ban(d1[x] - s[x], s[x] - a[r]), 1);
        }
    }
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        dfs0(x, x);
        x = dfsc(x, x, x);

        solvv(x);
        c[x] = true;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
                q.push(h);
        }
    }

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
    {
        solv();
    }
    return 0;
}