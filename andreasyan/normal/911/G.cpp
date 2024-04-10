#include <bits/stdc++.h>
using namespace std;
const int N = 200005, m = 100;
struct ban
{
    bool z;
    int x, y;
    int t;
    ban(){}
    ban(bool z, int x, int y, int t)
    {
        this->z = z;
        this->x = x;
        this->y = y;
        this->t = t;
    }
};

int n;
int a[N];

vector<ban> b[N];

int t[N * 4][m + 2];
void mer(int pos)
{
    for (int i = 1; i <= m; ++i)
    {
        t[pos][i] = t[pos * 2 + 1][t[pos * 2][i]];
    }
}
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        for (int i = 1; i <= m; ++i)
            t[pos][i] = i;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    mer(pos);
}
void ubd(int tl, int tr, int x, int xx, int yy, int pos)
{
    if (tl == tr)
    {
        if (xx == -1)
        {
            for (int i = 1; i <= m; ++i)
                t[pos][i] = i;
        }
        else
        {
            t[pos][xx] = yy;
        }
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, xx, yy, pos * 2);
    else
        ubd(m + 1, tr, x, xx, yy, pos * 2 + 1);
    mer(pos);
}

int ans[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int q;
    scanf("%d", &q);
    for (int ii = 1; ii <= q; ++ii)
    {
        int l, r;
        int x, y;
        scanf("%d%d%d%d", &l, &r, &x, &y);
        b[l].push_back(ban(true, x, y, ii));
        b[r + 1].push_back(ban(false, x, y, ii));
    }
    bil(1, q, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < b[i].size(); ++j)
        {
            if (b[i][j].z)
                ubd(1, q, b[i][j].t, b[i][j].x, b[i][j].y, 1);
            else
                ubd(1, q, b[i][j].t, -1, -1, 1);
        }
        ans[i] = t[1][a[i]];
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}