#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 1000000009000000009;

int n;
int p[N];
int a[N];
int u[N];

long long minu[N * 4];
long long laz[N * 4];
void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    minu[pos * 2] += laz[pos];
    minu[pos * 2 + 1] += laz[pos];
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

long long qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return minu[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        u[p[i]] = i;
    for (int i = 1; i <= n; ++i)
        ubd(0, n, i, n, a[u[i]], 1);
    long long ans = INF;
    for (int i = 1; i < n; ++i)
    {
        ubd(0, n, p[i], n, -a[i], 1);
        ubd(0, n, 0, p[i] - 1, a[i], 1);
        ans = min(ans, minu[1]);
    }
    printf("%lld\n", ans);
    return 0;
}