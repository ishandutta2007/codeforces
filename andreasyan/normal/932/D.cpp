#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 400005;

int qq;
int n;

int a[N];

const int m = 20;

int pp[N][m];
long long s[N][m];
int d[N];

void clcc(int x)
{
    d[x] = d[pp[x][0]] + 1;
    if (x == pp[x][0])
        s[x][0] = 0;
    else
        s[x][0] = a[pp[x][0]];
    for (int i = 1; i < m; ++i)
    {
        pp[x][i] = pp[pp[x][i - 1]][i - 1];
        s[x][i] = s[x][i - 1] + s[pp[x][i - 1]][i - 1];
    }
}

int p[N][m];
int maxu[N][m];

void clc(int x)
{
    if (x == p[x][0])
        maxu[x][0] = -1;
    else
        maxu[x][0] = a[p[x][0]];
    for (int i = 1; i < m; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
        maxu[x][i] = max(maxu[x][i - 1], maxu[p[x][i - 1]][i - 1]);
    }
    if (maxu[x][m - 1] < a[x])
    {
        pp[x][0] = x;
        clcc(x);
        return;
    }
    int y = x;
    for (int i = m - 1; i >= 0; --i)
    {
        if (maxu[y][i] < a[x])
        {
            y = p[y][i];
        }
    }
    pp[x][0] = p[y][0];
    clcc(x);
}

int qry(int x, long long y)
{
    if (a[x] > y)
        return 0;
    int xx = x;
    y -= a[x];
    for (int i = m - 1; i >= 0; --i)
    {
        if (s[x][i] <= y)
        {
            y -= s[x][i];
            x = pp[x][i];
        }
    }
    return (d[xx] - d[x] + 1);
}

int main()
{
    scanf("%d", &qq);
    n = 1;
    p[1][0] = 1;
    clc(1);
    long long ans = 0;
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            long long p_, q;
            scanf("%I64d%I64d", &p_, &q);
            int r = (p_ ^ ans), w = (q ^ ans);
            ++n;
            p[n][0] = r;
            a[n] = w;
            clc(n);
        }
        else
        {
            long long p, q;
            scanf("%I64d%I64d", &p, &q);
            int x = (p ^ ans);
            long long y = (q ^ ans);
            ans = qry(x, y);
            printf("%d\n", ans);
        }
    }
    return 0;
}