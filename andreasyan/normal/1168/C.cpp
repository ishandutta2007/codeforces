#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, q;
int a[N];

int t[N * 4][20];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        for (int j = 0; j < 20; ++j)
        {
            if ((a[tl] & (1 << j)))
                t[pos][j] = a[tl];
            else
                t[pos][j] = (1 << j);
        }
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    for (int k = 0; k < 20; ++k)
    {
        t[pos][k] = t[pos * 2][k];
        for (int j = 0; j < 20; ++j)
        {
            if ((t[pos * 2][k] & (1 << j)))
                t[pos][k] |= t[pos * 2 + 1][j];
        }
    }
}

int u;
void qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
    {
        int uu = u;
        for (int k = 0; k < 20; ++k)
        {
            if ((uu & (1 << k)))
            {
                u = u | t[pos][k];
            }
        }
        return;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        qry(tl, m, l, r, pos * 2);
    else if (l > m)
        qry(m + 1, tr, l, r, pos * 2 + 1);
    else
    {
        qry(tl, m, l, m, pos * 2);
        qry(m + 1, tr, m + 1, r, pos * 2 + 1);
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    bil(1, n, 1);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        u = a[x];
        qry(1, n, x, y, 1);
        if ((u & a[y]))
            printf("Shi\n");
        else
            printf("Fou\n");
    }
    return 0;
}