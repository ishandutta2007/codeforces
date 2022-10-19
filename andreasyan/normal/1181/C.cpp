#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
char a[N][N];

int u[N][N];

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
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return min(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int uu[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (a[i][j] == a[i][j + 1])
                u[i][j] = u[i][j + 1];
            else
                u[i][j] = j;
        }
    }
    long long ans = 0;
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
            ubd(0, n - 1, i, u[i][j], 1);
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i][j] == a[i + 1][j])
                uu[i] = uu[i + 1];
            else
                uu[i] = i;
        }
        for (int i = n - 1; i >= 0; --i)
        {
            int i1 = uu[i] + 1;
            if (i1 == n)
                continue;
            int i2 = uu[i1] + 1;
            if (i2 == n)
                continue;
            int i3 = uu[i2] + 1;
            if (i1 - i == i2 - i1)
            {
                if (i3 - i2 >= i2 - i1)
                {
                    int q = qry(0, n - 1, i, i2 + (i2 - i1) - 1, 1) - j + 1;
                    ans += q;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}