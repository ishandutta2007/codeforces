#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int i;
    int k, u;
};
bool operator<(const ban& a, const ban& b)
{
    return a.k < b.k;
}
struct ban1
{
    int i;
    int x;
};
bool operator<(const ban1& a, const ban1& b)
{
    if (a.x > b.x)
        return true;
    if (a.x < b.x)
        return false;
    return a.i < b.i;
}

int n;
ban1 a[N];
int aa[N];
int m;
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
int qry(int tl, int tr, int k, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (t[pos * 2] >= k)
        return qry(tl, m, k, pos * 2);
    return qry(m + 1, tr, k - t[pos * 2], pos * 2 + 1);
}

int ans[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].x);
        a[i].i = i;
        aa[i] = a[i].x;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &b[i].k, &b[i].u);
        b[i].i = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int j = 0;
    for (int i = 1; i <= m; ++i)
    {
        while (j < b[i].k)
        {
            ++j;
            ubd(1, n, a[j].i, 1);
        }
        ans[b[i].i] = aa[qry(1, n, b[i].u, 1)];
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}