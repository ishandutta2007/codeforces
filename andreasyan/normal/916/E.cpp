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
const int N = 100005;

int n, qq;
int a[N];
vector<int> g[N];
int r;

int tin[N], tout[N], ti;
const int m = 18;
int p[N][m];
int d[N];
void dfs(int x, int p0)
{
    tin[x] = ++ti;
    p[x][0] = p0;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    d[x] = d[p0] + 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int go(int x, int y)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return x;
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    return p[go(x, y)][0];
}

ll t[N * 4], laz[N * 4];

void shi(int tl, int tr, int pos)
{
    int m = (tl + tr) / 2;
    t[pos * 2] += (m - tl + 1) * laz[pos];
    laz[pos * 2] += laz[pos];
    t[pos * 2 + 1] += (tr - m) * laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] += (tr - tl + 1) * 1LL * y;
        laz[pos] += y;
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        ubd(1, n, tin[i], tin[i], a[i], 1);
    r = 1;
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            scanf("%d", &r);
        }
        else if (ty == 2)
        {
            int x, y, u;
            scanf("%d%d%d", &x, &y, &u);
            int z;
            if (isp(r, x) && isp(r, y))
                z = lca(x, y);
            else if (!isp(r, x) && !isp(r, y))
            {
                int z1 = lca(r, x);
                int z2 = lca(r, y);
                int z3 = lca(x, y);
                z = z1;
                if (d[z2] > d[z])
                    z = z2;
                if (d[z3] > d[z])
                    z = z3;
            }
            else
                z = r;
            if (!isp(z, r))
                ubd(1, n, tin[z], tout[z], u, 1);
            else
            {
                if (z == r)
                    ubd(1, n, 1, n, u, 1);
                else
                {
                    ubd(1, n, 1, n, u, 1);
                    ubd(1, n, tin[go(r, z)], tout[go(r, z)], -u, 1);
                }
            }
        }
        else if (ty == 3)
        {
            int x;
            scanf("%d", &x);
            if (!isp(x, r))
                printf("%lld\n", qry(1, n, tin[x], tout[x], 1));
            else
            {
                if (x == r)
                    printf("%lld\n", qry(1, n, 1, n, 1));
                else
                    printf("%lld\n", qry(1, n, 1, n, 1) -
                                        qry(1, n, tin[go(r, x)], tout[go(r, x)], 1));
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}