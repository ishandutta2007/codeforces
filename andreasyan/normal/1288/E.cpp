#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, m;
int a[N];

vector<int> v[N];

int u[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (x == 0)
        return;
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
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
         return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return qry(tl, m, l, min(m, r), pos * 2) +
        qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int t1[N * 4];
void ubd1(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t1[pos] = 1;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd1(tl, m, x, pos * 2);
    else
        ubd1(m + 1, tr, x, pos * 2 + 1);
    t1[pos] = t1[pos * 2] + t1[pos * 2 + 1];
}
int qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
         return 0;
    if (tl == l && tr == r)
        return t1[pos];
    int m = (tl + tr) / 2;
    return qry1(tl, m, l, min(m, r), pos * 2) +
        qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int ans[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
    {
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (u[a[i]])
            ans[i] = qry(1, m, u[a[i]] + 1, i - 1, 1);
        else
        {
            ans[i] = qry1(1, n, a[i] + 1, n, 1);
            ubd1(1, n, a[i], 1);
        }
        ubd(1, m, u[a[i]], 0, 1);
        u[a[i]] = i;
        ubd(1, m, u[a[i]], 1, 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        int minu = i, maxu = i;
        if (!v[i].empty())
        {
            minu = 1;
        }
        if (v[i].empty())
        {
            maxu = i + qry1(1, n, i + 1, n, 1);
        }
        else
        {
            maxu = i + ans[v[i][0]];
            for (int j = 1; j < v[i].size(); ++j)
                maxu = max(maxu, 1 + ans[v[i][j]]);
            maxu = max(maxu, 1 + qry(1, m, v[i].back() + 1, m, 1));
        }
        printf("%d %d\n", minu, maxu);
    }
    return 0;
}