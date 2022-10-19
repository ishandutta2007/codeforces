#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
struct ban
{
    int i;
    long long x;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.i < b.i;
}

long long n;
int m, q;
ban a[N];
ban b[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = 1;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}
int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (t[pos * 2] >= x)
        return qry(tl, m, x, pos * 2);
    return qry(m + 1, tr, x - t[pos * 2], pos * 2 + 1);
}

int ans[N];
int main()
{
    scanf("%lld%d%d", &n, &m, &q);
    for (int i = 1; i <= m; ++i)
        a[i].i = i;
    for (int i = 1; i <= n; ++i)
    {
        long long x;
        scanf("%lld", &x);
        a[x].x++;
    }
    for (int i = 1; i <= q; ++i)
    {
        b[i].i = i;
        scanf("%lld", &b[i].x);
    }
    sort(a + 1, a + m + 1);
    sort(b + 1, b + q + 1);
    int i = 1, j = 1;
    ubd(1, m, a[i].i, 1);
    while (i <= m && a[i].x == a[i + 1].x)
    {
        ++i;
        ubd(1, m, a[i].i, 1);
    }
    while (i < m)
    {
        long long u = (i * (a[i + 1].x - a[i].x));
        while (j <= q && b[j].x <= n + u)
        {
            ans[b[j].i] = qry(1, m, (b[j].x - n - 1) % i + 1, 1);
            ++j;
        }
        ++i;
        ubd(1, m, a[i].i, 1);
        while (i <= m && a[i].x == a[i + 1].x)
        {
            ++i;
            ubd(1, m, a[i].i, 1);
        }
        n += u;
    }
    while (j <= q)
    {
        ans[b[j].i] = (b[j].x - n - 1) % i + 1;
        ++j;
    }
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}