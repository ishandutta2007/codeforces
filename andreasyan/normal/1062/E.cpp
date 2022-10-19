#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, qq;
vector<int> a[N];

const int m = 17;
int p[N][m];
int tin[N], tout[N], ti;
int d[N];
void dfs(int x)
{
    tin[x] = ++ti;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        d[h] = d[x] + 1;
        dfs(h);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (x == -1)
        return y;
    if (y == -1)
        return x;
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

struct ban
{
    int l0;
    int x1, l1;
    int x2, l2;
    ban()
    {
        l0 = -1;
        x1 = -1;
        l1 = -1;
        x2 = -1;
        l2 = -1;
    }
    ban(int x)
    {
        l0 = x;
        x1 = x;
        l1 = -1;
        x2 = x;
        l2 = -1;
    }
};

ban t[N * 4];

ban mer(const ban& a, const ban& b)
{
    ban res;
    res.l0 = lca(a.l0, b.l0);
    bool z = false;
    int l;
    if (a.l1 != a.l0)
    {
        l = lca(a.l1, b.l0);
        if (l != res.l0)
        {
            if (!z)
            {
                res.x1 = a.x1;
                res.l1 = l;
                z = true;
            }
            else if (l != res.l1)
            {
                res.x2 = a.x1;
                res.l2 = l;
            }
        }
    }
    if (a.l2 != a.l0)
    {
        l = lca(a.l2, b.l0);
        if (l != res.l0)
        {
            if (!z)
            {
                res.x1 = a.x2;
                res.l1 = l;
                z = true;
            }
            else if (l != res.l1)
            {
                res.x2 = a.x2;
                res.l2 = l;
            }
        }
    }
    if (b.l1 != b.l0)
    {
        l = lca(a.l0, b.l1);
        if (l != res.l0)
        {
            if (!z)
            {
                res.x1 = b.x1;
                res.l1 = l;
                z = true;
            }
            else if (l != res.l1)
            {
                res.x2 = b.x1;
                res.l2 = l;
            }
        }
    }
    if (b.l2 != b.l0)
    {
        l = lca(a.l0, b.l2);
        if (l != res.l0)
        {
            if (!z)
            {
                res.x1 = b.x2;
                res.l1 = l;
                z = true;
            }
            else if (l != res.l1)
            {
                res.x2 = b.x2;
                res.l2 = l;
            }
        }
    }
    if (res.x1 == -1)
    {
        res.x1 = a.x1;
        res.l1 = res.l0;
    }
    if (res.x2 == -1)
    {
        res.x2 = a.x1;
        res.l2 = res.l0;
    }
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(tl);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &p[i][0]);
        a[p[i][0]].push_back(i);
    }
    p[1][0] = 1;
    dfs(1);
    bil(1, n, 1);
    while (qq--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ban u = qry(1, n, l, r, 1);
        if (d[u.l1] > d[u.l2])
        {
            printf("%d %d\n", u.x1, d[u.l1]);
        }
        else
        {
            printf("%d %d\n", u.x2, d[u.l2]);
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