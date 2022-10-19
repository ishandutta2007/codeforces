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
const int N = 1000006;

int n, k;
int p[N];
vector<int> a[N];

int tin[N], tout[N], ti;
int rtin[N];
int u[N];

vector<int> v;
void dfs0(int x)
{
    tin[x] = ++ti;
    rtin[tin[x]] = x;
    v.push_back(x);
    u[x] = v[max(0, sz(v) - 1 - k)];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs0(h);
    }
    v.pop_back();
    tout[x] = ti;
}

int s[N * 4];
void ubd_s(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        s[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd_s(tl, m, x, y, pos * 2);
    else
        ubd_s(m + 1, tr, x, y, pos * 2 + 1);
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
}

int qry_s(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (!s[pos])
        return 0;
    if (tl == tr)
    {
        return tl;
    }
    int m = (tl + tr) / 2;
    int u = qry_s(tl, m, l, min(m, r), pos * 2);
    if (u)
        return u;
    return qry_s(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

void dfs1(int x)
{
    ubd_s(1, n, tin[x], 0, 1);
    while (1)
    {
        int h = qry_s(1, n, tin[u[x]], tout[u[x]], 1);
        if (!h)
            break;
        h = rtin[h];
        dfs1(h);
    }
    v.push_back(x);
}

int m;
int c[N];

vector<int> t[N * 4];
void ubd_t(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos].push_back(y);
        return;
    }
    int m = (tl + tr) / 2;
    ubd_t(tl, m, l, min(m, r), y, pos * 2);
    ubd_t(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int qry_t(int tl, int tr, int x, int pos)
{
    while (!t[pos].empty() && c[t[pos].back()])
        t[pos].pop_back();
    if (!t[pos].empty())
        return t[pos].back();
    if (tl == tr)
        return 0;
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry_t(tl, m, x, pos * 2);
    return qry_t(m + 1, tr, x, pos * 2 + 1);
}

void dfs2(int x)
{
    c[x] = m;
    while (1)
    {
        int h = qry_t(1, n, tin[x], 1);
        if (h == 0)
            break;
        dfs2(h);
    }
}

vector<int> cv[N];
bool cc[N];
int dp[N];

int maxu[N * 4];
void ubd_max(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd_max(tl, m, x, y, pos * 2);
    else
        ubd_max(m + 1, tr, x, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

int qry_max(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
    {
        return maxu[pos];
    }
    int m = (tl + tr) / 2;
    return max(qry_max(tl, m, l, min(m, r), pos * 2),
               qry_max(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void dfs3(int x)
{
    cc[x] = true;
    for (int i = 0; i < cv[x].size(); ++i)
    {
        int xx = cv[x][i];
        ubd_s(1, n, tin[xx], 0, 1);
    }
    for (int i = 0; i < cv[x].size(); ++i)
    {
        int xx = cv[x][i];
        while (1)
        {
            int h = qry_s(1, n, tin[u[xx]], tout[u[xx]], 1);
            if (!h)
                break;
            h = rtin[h];
            if (!cc[c[h]])
                dfs3(c[h]);
        }
    }
    for (int i = 0; i < cv[x].size(); ++i)
    {
        int xx = cv[x][i];
        dp[x] = max(dp[x], sz(cv[x]) + qry_max(1, n, tin[u[xx]], tout[u[xx]], 1));
    }
    for (int i = 0; i < cv[x].size(); ++i)
    {
        int xx = cv[x][i];
        ubd_max(1, n, tin[xx], dp[x], 1);
    }
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int x = 2; x <= n; ++x)
    {
        scanf("%d", &p[x]);
        a[p[x]].push_back(x);
    }
    dfs0(1);

    for (int x = 1; x <= n; ++x)
    {
        if (a[x].empty())
        {
            ubd_s(1, n, tin[x], 1, 1);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        if (a[x].empty())
        {
            if (qry_s(1, n, tin[x], tout[x], 1))
                dfs1(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (a[x].empty())
        {
            ubd_t(1, n, tin[u[x]], tout[u[x]], x, 1);
        }
    }
    reverse(all(v));
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++m;
            dfs2(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (a[x].empty())
        {
            cv[c[x]].push_back(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (a[x].empty())
        {
            ubd_s(1, n, tin[x], 1, 1);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (!cc[i])
        {
            dfs3(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}