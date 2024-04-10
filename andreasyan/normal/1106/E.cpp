#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 202;
const long long INF = 100005000000009;
struct ban
{
    int l, r, d, w;
    ban()
    {
        l = r = d = w = 0;
    }
    ban(int l, int r, int d, int w)
    {
        this->l = l;
        this->r = r;
        this->d = d;
        this->w = w;
    }
};
bool operator>(const ban& a, const ban& b)
{
    if (a.w > b.w)
        return true;
    if (a.w < b.w)
        return false;
    return a.d > b.d;
}

int n, m, k;
ban a[N];

ban maxu1[N * 4], maxu2[N * 4];

void ubd(int tl, int tr, int l, int r, ban x, int pos)
{
    if (tl == l && tr == r)
    {
        if (x > maxu1[pos])
        {
            maxu2[pos] = maxu1[pos];
            maxu1[pos] = x;
        }
        else if (x > maxu2[pos])
            maxu2[pos] = x;
        return;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, x, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, x, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, x, pos * 2);
        ubd(m + 1, tr, m + 1, r, x, pos * 2 + 1);
    }
}

ban max1, max2;
void qry(int tl, int tr, int x, int pos)
{
    if (maxu1[pos] > max1)
        max1 = maxu1[pos];
    else if (maxu1[pos] > max2)
        max2 = maxu1[pos];
    if (maxu2[pos] > max2)
        max2 = maxu2[pos];
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    if (x <= m)
        qry(tl, m, x, pos * 2);
    else
        qry(m + 1, tr, x, pos * 2 + 1);
}


long long dp[N][M];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
        cin >> a[i].l >> a[i].r >> a[i].d >> a[i].w;

    for (int i = 1; i <= k; ++i)
    {
        ubd(1, n, a[i].l, a[i].r, a[i], 1);
    }

    for (int i = 0; i <= n; ++i)
        for (int k = 0; k <= m; ++k)
            dp[i][k] = INF;

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
            cout << "";
        for (int k = 0; k <= m; ++k)
        {
            max1 = ban(0, 0, 0, 0);
            max2 = max1;
            qry(1, n, i + 1, 1);
            dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][k]);
            if (max1.w != 0)
                dp[max1.d][k] = min(dp[max1.d][k], dp[i][k] + max1.w);
            else
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][k]);
        }
    }
    long long ans = INF;
    for (int k = 0; k <= m; ++k)
        ans = min(ans, dp[n][k]);
    cout << ans << endl;
    return 0;
}