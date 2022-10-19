#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;
const long long INF = 1000000009000000009;

int n;
int a[N];

long long t[N * 4];
long long laz[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

void shi(int pos)
{
    if (!laz[pos])
        return;
    t[pos * 2] += laz[pos];
    t[pos * 2 + 1] += laz[pos];
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

long long qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, char> ka()
{
    bool z = false;
    int x = 0;
    while (1)
    {
        char y = getchar();
        if (y == '-')
            z = true;
        else if ('0' <= y && y <= '9')
            x = (x * 10) + (y - '0');
        else
        {
            if (!z)
                return m_p(x, y);
            else
                return m_p(-x, y);
        }
    }
}

int main()
{
    n = ka().first;
    for (int i = 0; i < n; ++i)
        a[i] = ka().first;
    bil(0, n - 1, 1);
    int q;
    q = ka().first;
    while (q--)
    {
        pair<int, char> l, r;
        int y;
        l = ka();
        r = ka();
        if (r.second == ' ')
        {
            y = ka().first;
            if (l.first <= r.first)
                ubd(0, n - 1, l.first, r.first, y, 1);
            else
            {
                ubd(0, n - 1, l.first, n - 1, y, 1);
                ubd(0, n - 1, 0, r.first, y, 1);
            }
        }
        else
        {
            if (l.first <= r.first)
                printf("%lld\n", qry(0, n - 1, l.first, r.first, 1));
            else
                printf("%lld\n", min(qry(0, n - 1, l.first, n - 1, 1),
                                     qry(0, n - 1, 0, r.first, 1)));
        }
    }
    return 0;
}