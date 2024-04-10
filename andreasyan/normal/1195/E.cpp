#include <bits/stdc++.h>
using namespace std;
const int N = 3003;

long long g[N * N], x, y, z;

int n, m, nn, mm;
int a[N][N];

int minu[N][N];

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
        return 0;
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2), qry(m + 1, tr, max(l, m + 1), r, pos * 2 + 1));
}

long long ans;

int main()
{
    cin >> n >> m >> nn >> mm;
    cin >> g[0] >> x >> y >> z;
    for (int i = 1; i <= n * m; ++i)
        g[i] = (g[i - 1] * x + y) % z;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = g[(i - 1) * m + j - 1];
        }
    }
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= nn; ++i)
            ubd(0, nn - 1, i % nn, a[i][j], 1);
        for (int i = 1; i <= n - nn + 1; ++i)
        {
            minu[i][j] = t[1];
            ubd(0, nn - 1, i % nn, a[i + nn][j], 1);
        }
    }
    for (int i = 1; i <= n - nn + 1; ++i)
    {
        for (int j = 1; j <= mm; ++j)
            ubd(0, mm - 1, j % mm, minu[i][j], 1);
        for (int j = 1; j <= m - mm + 1; ++j)
        {
            ans += t[1];
            ubd(0, mm - 1, j % mm, minu[i][j + mm], 1);
        }
    }
    cout << ans << endl;
    return 0;
}