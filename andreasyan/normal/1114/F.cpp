#include <bits/stdc++.h>
using namespace std;
const int N = 400005, M = 1000000007, K = 302;

int ast(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        int y = ast(x, n / 2);
        return (1LL * y * y) % M;
    }
    else
    {
        int y = ast(x, n - 1);
        return (1LL * y * x) % M;
    }
}


bool c[K];
vector<int> v;

long long q[K];

int b[K];

void pre()
{
    c[0] = true;
    c[1] = true;
    for (int i = 0; i < K; ++i)
    {
        if (c[i] == true)
            continue;
        for (int j = i * i; j < K; j += i)
        {
            c[j] = true;
        }
    }
    for (int i = 0; i < K; ++i)
    {
        if (!c[i])
            v.push_back(i);
    }

    for (int i = 1; i < K; ++i)
    {
        int x = i;
        for (int j = 0; j < v.size(); ++j)
        {
            if (x % v[j] == 0)
            {
                q[i] |= (1LL << j);
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
        b[i] = ast(v[i], M - 2);
}

int n, qq;
int a[N];

struct ban
{
    int mul, laz;
    long long x, lazx;
    ban()
    {
        laz = 1;
        lazx = 0;
    }
};

ban t[N * 4];

ban mer(const ban& a, const ban& b)
{
    ban res;
    res.mul = (1LL * a.mul * b.mul) % M;
    res.x = a.x | b.x;
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].mul = a[tl];
        t[pos].x = q[a[tl]];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void shi(int tl, int tr, int pos)
{
    int m = (tl + tr) / 2;
    t[pos * 2].mul = (1LL * t[pos * 2].mul * ast(t[pos].laz, (m - tl + 1))) % M;
    t[pos * 2 + 1].mul = (1LL * t[pos * 2 + 1].mul * ast(t[pos].laz, (tr - m))) % M;
    t[pos * 2].laz = (1LL * t[pos * 2].laz * t[pos].laz) % M;
    t[pos * 2 + 1].laz = (1LL * t[pos * 2 + 1].laz * t[pos].laz) % M;

    t[pos * 2].x = t[pos * 2].x | t[pos].lazx;
    t[pos * 2 + 1].x = t[pos * 2 + 1].x | t[pos].lazx;
    t[pos * 2].lazx = t[pos * 2].lazx | t[pos].lazx;
    t[pos * 2 + 1].lazx = t[pos * 2 + 1].lazx | t[pos].lazx;

    t[pos].laz = 1;
    t[pos].lazx = 0;
}

void ubd(int tl, int tr, int l, int r, int x, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos].mul = (1LL * t[pos].mul * ast(x, r - l + 1)) % M;
        t[pos].laz = (1LL * t[pos].laz * x) % M;
        t[pos].x |= q[x];
        t[pos].lazx |= q[x];
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, x, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, x, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, x, pos * 2);
        ubd(m + 1, tr, m + 1, r, x, pos * 2 + 1);
    }
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int main()
{
    pre();
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    bil(1, n, 1);
    while (qq--)
    {
        char ty[10];
        scanf(" %s", ty);
        if (ty[0] == 'T')
        {
            int l, r;
            scanf("%d%d", &l, &r);
            ban z = qry(1, n, l, r, 1);
            int ans = z.mul;
            for (int i = 0; i < v.size(); ++i)
            {
                if ((z.x & (1LL << i)))
                {
                    ans = (ans - ((1LL * ans * b[i]) % M) + M) % M;
                }
            }
            printf("%d\n", ans);
        }
        else
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            ubd(1, n, l, r, x, 1);
        }
    }
    return 0;
}