#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = N * 70;
struct ban
{
    long long a, b;
};

int n;

int z;
int ll[M], rr[M];
ban t[M];

int ubd(int tl, int tr, int l, int r, long long a, long long b, int pos)
{
    int ypos = ++z;
    ll[ypos] = ll[pos];
    rr[ypos] = rr[pos];
    t[ypos] = t[pos];
    if (tl == l && tr == r)
    {
        t[ypos].a += a;
        t[ypos].b += b;
        return ypos;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
    {
        ll[ypos] = ubd(tl, m, l, r, a, b, ll[pos]);
    }
    else if (l > m)
    {
        rr[ypos] = ubd(m + 1, tr, l, r, a, b, rr[pos]);
    }
    else
    {
        ll[ypos] = ubd(tl, m, l, m, a, b, ll[pos]);
        rr[ypos] = ubd(m + 1, tr, m + 1, r, a, b, rr[pos]);
    }
    return ypos;
}

long long qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos].a * x + t[pos].b;
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, ll[pos]) + t[pos].a * x + t[pos].b;
    return qry(m + 1, tr, x, rr[pos]) + t[pos].a * x + t[pos].b;
}

int upos[N];
long long p[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    int vpos = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x1, x2, y1, a, b, y2;
        scanf("%d%d%d%d%d%d", &x1, &x2, &y1, &a, &b, &y2);
        vpos = ubd(0, N, 0, x1, 0, y1, vpos);
        vpos = ubd(0, N, x1 + 1, x2, a, b, vpos);
        vpos = ubd(0, N, x2 + 1, N, 0, y2, vpos);
        upos[i] = vpos;
        p[i] = p[i - 1] + y2;
    }
    int q;
    scanf("%d", &q);
    long long last = 0;
    while (q--)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        x = (x + last) % 1000000000;
        if (x > N)
        {
            last = p[r] - p[l - 1];
        }
        else
        {
            last = qry(0, N, x, upos[r]) - qry(0, N, x, upos[l - 1]);
        }
        printf("%lld\n", last);
    }
    return 0;
}