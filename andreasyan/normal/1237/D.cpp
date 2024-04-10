#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];

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
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        if (t[pos] <= y)
            return 0;
        if (tl == tr)
            return tl;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, y, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, y, pos * 2 + 1);
    int yans = qry(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    if (yans)
        return yans;
    return qry(tl, m, l, m, y, pos * 2);
}

int b[N];

int qry1(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        if (t[pos] < y)
            return N;
        if (tl == tr)
            return tl;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry1(tl, m, l, r, y, pos * 2);
    if (l > m)
        return qry1(m + 1, tr, l, r, y, pos * 2 + 1);
    int yans = qry1(tl, m, l, m, y, pos * 2);
    if (yans < N)
        return yans;
    return qry1(m + 1, tr, m + 1, r, y, pos * 2 + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = n + 1; i <= n + n; ++i)
        a[i] = a[i - n];
    for (int i = 1; i <= n + n; ++i)
        ubd(1, n + n, i, a[i], 1);
    for (int i = n + 1; i <= n + n; ++i)
    {
        b[i] = qry(1, n + n, 1, i, a[i] * 2, 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (b[i + n] == 0)
            b[i] = 0;
        else
            b[i] = i - ((i + n) - b[i + n]);
    }
    for (int i = n + n + 1; i <= n + n + n; ++i)
    {
        if (b[i - n] == 0)
            b[i] = 0;
        else
            b[i] = i - ((i - n) - b[i - n]);
    }
    for (int i = 1; i <= n + n + n; ++i)
        ubd(1, n + n + n, i, b[i], 1);
    for (int i = 1; i <= n; ++i)
    {
        int ans = qry1(1, n + n + n, i, n + n + n, i, 1);
        if (ans == N)
            printf("-1 ");
        else
            printf("%d ", (ans - i));
    }
    printf("\n");
    return 0;
}