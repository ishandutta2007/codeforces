#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];

int t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = (1 << (a[tl] - 'a'));
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = (t[pos * 2] | t[pos * 2 + 1]);
}
void ubd(int tl, int tr, int x, char y, int pos)
{
    if (tl == tr)
    {
        t[pos] = (1 << (y - 'a'));
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] | t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return (qry(tl, m, l, m, pos * 2) | qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    bil(0, n - 1, 1);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x;
            char y;
            scanf("%d %c", &x, &y);
            --x;
            ubd(0, n - 1, x, y, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            int x = qry(0, n - 1, l, r, 1);
            int q = 0;
            for (int i = 0; i < 26; ++i)
            {
                if ((x & (1 << i)))
                    ++q;
            }
            printf("%d\n", q);
        }
    }
    return 0;
}