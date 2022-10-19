#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int o[N];

int n;
int a[N];

int t[11][N][10][4];

void bil(int mn)
{
    for (int x = 1; x <= n; ++x)
    {
        int xx = x;
        while (x <= n)
        {
            t[mn][x][(xx % mn)][0]++;
            x += (x & (-x));
        }
        x = xx;
    }
}

void ubd(int mn, int x, int y)
{
    int xx = x;
    while (x <= n)
    {
        t[mn][x][(xx % mn)][a[xx]]--;
        t[mn][x][(xx % mn)][y]++;
        x += (x & (-x));
    }
    a[xx] = y;
}

int ans[10][4];

void qry(int mn, int l, int r)
{
    for (int i = 0; i < mn; ++i)
        for (int j = 0; j < 4; ++j)
            ans[i][j] = 0;
    while (r >= 1)
    {
        for (int i = 0; i < mn; ++i)
        {
            for (int j = 0; j < 4; ++j)
                ans[i][j] += t[mn][r][i][j];
        }
        r -= (r & (-r));
    }
    --l;
    while (l >= 1)
    {
        for (int i = 0; i < mn; ++i)
        {
            for (int j = 0; j < 4; ++j)
                ans[i][j] -= t[mn][l][i][j];
        }
        l -= (l & (-l));
    }
}

char aa[N];
int main()
{
    ios_base::sync_with_stdio(false);
    o['T'] = 1;
    o['G'] = 2;
    o['C'] = 3;
    cin >> aa;
    n = strlen(aa);
    for (int mn = 1; mn <= 10; ++mn)
        bil(mn);
    for (int i = 1; i <= n; ++i)
    {
        for (int mn = 1; mn <= 10; ++mn)
        {
            a[i] = 0;
            ubd(mn, i, o[aa[i - 1]]);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 2)
        {
            int l, r;
            cin >> l >> r >> aa;
            int mn = strlen(aa);
            qry(mn, l, r);
            int yans = 0;
            for (int i = 0, ii = l; i < mn; ++i, ++ii)
                yans += ans[(ii % mn)][o[aa[i]]];
            cout << yans << endl;
        }
        else
        {
            int x;
            char y;
            cin >> x >> y;
            int z = a[x];
            for (int mn = 1; mn <= 10; ++mn)
            {
                a[x] = z;
                ubd(mn, x, o[y]);
            }
        }
    }
    return 0;
}