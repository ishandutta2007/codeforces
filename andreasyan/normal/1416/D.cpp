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

int n, m, q;
int a[N];
pair<int, int> b[N];
pair<int, int> u[N];
bool c[N];

int z;
int p0[N];
int fi(int x)
{
    if (x == p0[x])
        return x;
    return p0[x] = fi(p0[x]);
}

vector<int> g[N];
int t[N];

const int l = 20;
int p[N][l];

int tin[N], tout[N], ti;

void dfs0(int x, int p0)
{
    c[x] = true;
    tin[x] = ++ti;
    p[x][0] = p0;
    for (int i = 1; i < l; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs0(h, x);
    }
    tout[x] = ti;
}

int go(int x, int y)
{
    for (int i = l - 1; i >= 0; --i)
    {
        if (t[p[x][i]] >= y)
            x = p[x][i];
    }
    return x;
}

pair<int, int> maxu[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = m_p(y, x);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 1);
    if (tl == l && tr == r)
    {
        return maxu[pos];
    }
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &b[i].fi, &b[i].se);
    }

    for (int i = 1; i <= q; ++i)
    {
        scanf("%d%d", &u[i].fi, &u[i].se);
        if (u[i].fi == 2)
            c[u[i].se] = true;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (!c[i])
            u[++q] = m_p(2, i);
    }

    for (int i = 0; i < N; ++i)
        p0[i] = i;
    z = n;
    for (int i = 1; i <= n; ++i)
        t[i] = q + 1;
    for (int i = q; i >= 1; --i)
    {
        if (u[i].fi == 2)
        {
            int j = u[i].se;
            int x = b[j].fi;
            int y = b[j].se;
            x = fi(x);
            y = fi(y);
            if (x == y)
                continue;
            ++z;
            p0[x] = z;
            p0[y] = z;
            g[z].push_back(x);
            g[z].push_back(y);
            t[z] = i;
        }
    }

    memset(c, false, sizeof c);
    for (int i = z; i >= 1; --i)
    {
        if (!c[i])
        {
            dfs0(i, i);
        }
    }

    for (int i = 0; i < N * 4; ++i)
        maxu[i] = m_p(0, 1);
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, z, tin[i], a[i], 1);
    }

    for (int i = 1; i <= q; ++i)
    {
        if (u[i].fi == 2)
            continue;
        int x = u[i].se;
        x = go(x, i);
        pair<int, int> u = qry(1, z, tin[x], tout[x], 1);
        printf("%d\n", u.fi);
        ubd(1, z, u.se, 0, 1);
    }
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