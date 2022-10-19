#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, w;
vector<int> a[N];

int t[N * 4];
void bil(int i, int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[i][tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(i, tl, m, pos * 2);
    bil(i, m + 1, tr, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return max(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

long long t1[N * 4];
void ubd1(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        t1[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd1(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd1(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd1(tl, m, l, m, y, pos * 2);
        ubd1(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
}
long long qry1(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t1[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return t1[pos] + qry1(tl, m, x, pos * 2);
    else
        return t1[pos] + qry1(m + 1, tr, x, pos * 2 + 1);
}

int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        a[i].push_back(0);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int m = a[i].size() - 1;
        bil(i, 1, m, 1);
        for (int j = 1; j <= m; ++j)
        {
            int l = max(1, j + m - w);
            int r = min(m, j);
            int u = qry(1, m, l, r, 1);
            if (j <= w - m)
                u = max(u, 0);
            if (j > m)
                u = max(u, 0);
            ubd1(1, w, j, j, u, 1);
        }
        for (int j = w; j >= w - m + 1; --j)
        {
            if (j <= m)
                break;
            int l = max(1, j + m - w);
            int r = min(m, j);
            int u = qry(1, m, l, r, 1);
            if (j <= w - m)
                u = max(u, 0);
            if (j > m)
                u = max(u, 0);
            ubd1(1, w, j, j, u, 1);
        }
        int maxu = 0;
        for (int j = 1; j <= m; ++j)
            maxu = max(maxu, a[i][j]);
        if (m + 1 <= w - m)
            ubd1(1, w, m + 1, w - m, maxu, 1);
    }
    for (int i = 1; i <= w; ++i)
        cout << qry1(1, w, i, 1) << ' ';
    cout << endl;
    return 0;
}