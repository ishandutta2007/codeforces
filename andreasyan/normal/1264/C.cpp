#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long M = 998244353;

long long ast(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

long long u[102];

void pre()
{
    for (int i = 1; i <= 100; ++i)
    {
        u[i] = (100 * ast(i, M - 2)) % M;
    }
}

int n;
int a[N];
bool c[N];

struct ban
{
    long long prol;
    long long ansl;
    long long ansr;
    long long ansm;
    bool z;
    ban(){}
    ban(bool zz, int x)
    {
        z = zz;
        if (z)
        {
            prol = 1;
            ansl = 0;
            ansr = u[x];
            ansm = 0;
        }
        else
        {
            prol = u[x];
            ansl = u[x];
            ansr = 0;
            ansm = 0;
        }
    }
};

ban t[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.z = (l.z || r.z);
    if (l.z)
    {
        res.ansl = l.ansl;
        res.prol = l.prol;
    }
    else
    {
        res.prol = (l.prol * r.prol) % M;
        res.ansl = (l.ansl * r.prol + r.ansl) % M;
    }
    if (r.z)
    {
        res.ansr = r.ansr;
    }
    else
    {
        if (!l.z)
            res.ansr = 0;
        else
        {
            res.ansr = (l.ansr * r.prol + r.ansl) % M;
        }
    }
    res.ansm = (l.ansm + r.ansm) % M;
    if (l.z && r.z)
        res.ansm = (res.ansm + (l.ansr * r.prol + r.ansl)) % M;
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(c[tl], a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(c[tl], a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

int main()
{
    pre();
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    c[1] = true;
    bil(1, n, 1);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        c[x] ^= true;
        ubd(1, n, x, 1);
        printf("%lld\n", (t[1].ansm + t[1].ansr) % M);
        /*long long ans = 0;
        long long yans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
            {
                ans += yans;
                yans = u[a[i]];
            }
            else
            {
                yans = (yans * u[a[i]] + u[a[i]]) % M;
            }
        }
        ans += yans;
        printf("%lld\n", ans);*/
    }
    return 0;
}