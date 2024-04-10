#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];
int m;
int b[N];
int s[N];

int t[N * 4];
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
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        b[i] = 0;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, q;
        scanf("%d%d", &x, &q);
        b[q] = max(b[q], x);
    }
    s[n + 1] = 0;
    for (int i = n; i >= 1; --i)
        s[i] = max(s[i + 1], b[i]);
    bil(1, n, 1);
    int k = 1;
    int yans = 0;
    while (k <= n)
    {
        int l = k, r = n;
        int ans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (s[m - k + 1] >= qry(1, n, k, m, 1))
            {
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        if (ans == -1)
        {
            printf("%d\n", ans);
            return;
        }
        ++yans;
        k = ans + 1;
    }
    printf("%d\n", yans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}