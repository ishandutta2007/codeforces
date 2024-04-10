#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
int a[N];

long long t[N * 4];
void ubd(int tl, int tr, int x, long long y, int pos)
{
    if (tl == tr)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

long long qry(int tl, int tr, int l, int r, int pos)
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
    return qry(tl, m, l, m, pos * 2) + qry(m + 1, tr, m + 1, r, pos * 2 + 1);
}

long long dpn[N];
long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        dpn[i] = 1;
    }

    for (int ii = 0; ii < k; ++ii)
    {
        memset(t, 0, sizeof t);
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = qry(1, n, 1, a[i] - 1, 1);
            ubd(1, n, a[i], dpn[i], 1);
        }
        for (int i = 1; i <= n; ++i)
            dpn[i] = dp[i];
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dp[i];

    cout << ans << endl;
    return 0;
}