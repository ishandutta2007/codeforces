#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n, m, qq;
vector<int> a[N];
int u[N];
vector<int> v[N];
int vu[N];

int d[N], q[N], pp[N];
void dfs0(int x, int p)
{
    pp[x] = p;
    d[x] = d[p] + 1;
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            swap(a[x][i], a[x].back());
            break;
        }
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
        if (q[h] > q[a[x][0]])
            swap(a[x][i], a[x][0]);
    }
}

int tin[N], tout[N], ti;
int f[N];
void dfs1(int x, int p)
{
    tin[x] = ++ti;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (i == 0)
            f[h] = f[x];
        else
            f[h] = h;
        dfs1(h, x);
    }
    tout[x] = ti;
}

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int qry(int x, int y)
{
    int ans = N;
    while (f[x] != f[y])
    {
        if (d[f[x]] < d[f[y]])
            swap(x, y);
        ans = min(ans, qry(1, n, tin[f[x]], tin[x], 1));
        x = pp[f[x]];
    }
    if (d[x] < d[y])
        swap(x, y);
    ans = min(ans, qry(1, n, tin[y], tin[x], 1));
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &qq);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &u[i]);
        v[u[i]].push_back(i);
    }
    dfs0(1, 1);
    dfs1(1, 1);
    for (int i = 0; i < N * 4; ++i)
        t[i] = N;
    for (int i = 1; i <= n; ++i)
    {
        if (!v[i].empty())
        {
            ubd(1, n, tin[i], v[i][0], 1);
        }
    }
    while (qq--)
    {
        int x, y, q;
        scanf("%d%d%d", &x, &y, &q);
        vector<int> ans;
        while (q--)
        {
            int i = qry(x, y);
            if (i == N)
                break;
            ans.push_back(i);
            ++vu[u[i]];
            if (vu[u[i]] < v[u[i]].size())
                ubd(1, n, tin[u[i]], v[u[i]][vu[u[i]]], 1);
            else
                ubd(1, n, tin[u[i]], N, 1);
        }
        printf("%d ", ans.size());
        for (int i = 0; i < ans.size(); ++i)
            printf("%d ", ans[i]);
        printf("\n");
        while (!ans.empty())
        {
            int i = ans.back();
            ans.pop_back();
            --vu[u[i]];
            ubd(1, n, tin[u[i]], v[u[i]][0], 1);
        }
    }
    return 0;
}