#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;

int n, k;
vector<int> a[N];

bool c[N];

int d[N];
int tin[N], tout[N], ti;
int pp[N];

void dfs(int x, int p)
{
    tin[x] = ++ti;
    d[x] = d[p] + 1;
    pp[x] = p;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
    tout[x] = ti;
}

int t[N * 4];

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (d[y] > d[t[pos]])
            t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    int u;
    if (x <= m)
        u = qry(tl, m, x, pos * 2);
    else
        u = qry(m + 1, tr, x, pos * 2 + 1);
    if (d[u] > d[t[pos]])
        return u;
    return t[pos];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    k = n - k;
    dfs(n, n);
    c[n] = true;
    --k;
    ubd(1, n, tin[n], tout[n], n, 1);
    for (int i = n - 1; i >= 1; --i)
    {
        if (c[i])
            continue;
        int y = qry(1, n, tin[i], 1);
        if (d[i] - d[y] <= k)
        {
            int x = i;
            while (1)
            {
                c[x] = true;
                --k;
                ubd(1, n, tin[x], tout[x], x, 1);
                x = pp[x];
                if (c[x])
                    break;
            }
        }
    }
    assert(k == 0);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}