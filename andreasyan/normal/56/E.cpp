// fast fast fast fast fast
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
struct ban
{
    int i;
    int x, h;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

int dp[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return max(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int ans[N];

int main()
{
    /////////////////////////////////////////////////////////////////////////////////
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        cin >> a[i].x >> a[i].h;
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; --i)
    {
        int l = i + 1, r = n;
        while (r - l > 4)
        {
            int m = (l + r) / 2;
            if (a[m].x <= a[i].x + a[i].h - 1)
                l = m;
            else
                r = m;
        }
        for (int m = r; m >= l; --m)
        {
            if (a[m].x <= a[i].x + a[i].h - 1)
            {
                dp[i] = qry(1, n, i + 1, m, 1);
                break;
            }
        }
        if (dp[i] == 0)
            dp[i] = i;
        ubd(1, n, i, dp[i], 1);
    }
    for (int i = 1; i <= n; ++i)
        ans[a[i].i] = dp[i] - i + 1;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    return 0;
}