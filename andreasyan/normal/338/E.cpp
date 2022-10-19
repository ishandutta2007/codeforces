#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m, h;
int b[N];
int a[N];
int u[N];

struct ban
{
    int sum;
    int minu;
    ban()
    {
        sum = 0;
        minu = 0;
    }
};

ban t[N * 4];
ban mer(const ban& l, const ban& r)
{
    ban res;
    res.sum = l.sum + r.sum;
    res.minu = min(l.minu, l.sum + r.minu);
    return res;
}
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos].sum += y;
        if (t[pos].sum < 0)
            t[pos].minu = t[pos].sum;
        else
            t[pos].minu = 0;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = m;
        int ans = m + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[i] + b[m] >= h)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        u[i] = ans;
    }
    for (int i = 1; i <= m; ++i)
        ubd(1, m + 1, i, -1, 1);
    for (int i = 1; i <= m; ++i)
        ubd(1, m + 1, u[i], 1, 1);
    int ans = 0;
    if (t[1].minu >= 0)
        ++ans;
    for (int i = m + 1; i <= n; ++i)
    {
        ubd(1, m + 1, u[i], 1, 1);
        ubd(1, m + 1, u[i - m], -1, 1);
        if (t[1].minu >= 0)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}