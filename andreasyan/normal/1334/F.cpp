#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 500005;
const long long INF = 1000000009000000009;

int n;
int a[N];
int p[N];

int m;
int b[N];

long long dp[N];

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
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

long long t1[N * 4];

void ubd1(int tl, int tr, int x, long long y, int pos)
{
    if (tl == tr)
    {
        t1[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd1(tl, m, x, y, pos * 2);
    else
        ubd1(m + 1, tr, x, y, pos * 2 + 1);
    t1[pos] = t1[pos * 2] + t1[pos * 2 + 1];
}

long long qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t1[pos];
    int m = (tl + tr) / 2;
    return (qry1(tl, m, l, min(m, r), pos * 2) +
            qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

long long minu[N];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i < m; ++i)
        minu[i] = INF;
    long long pans = 0;
    for (int i = n; i >= 1; --i)
    {
        int j = lower_bound(b + 1, b + m + 1, a[i]) - b;
        if (b[j] != a[i])
            j = -1;
        dp[i] = INF;
        if (j != -1 && minu[j] != INF)
            dp[i] = minu[j] + qry(1, n, a[i] + 1, n, 1) + qry1(1, n, 1, a[i], 1);
        if (dp[i] != INF)
            minu[j - 1] = min(minu[j - 1], dp[i] - qry(1, n, b[j - 1] + 1, n, 1) - qry1(1, n, 1, b[j - 1], 1) - p[i]);
        ubd(1, n, a[i], p[i], 1);
        if (p[i] < 0)
            ubd1(1, n, a[i], p[i], 1);
    }
    long long ans = INF;
    long long pp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == b[1])
        {
            if (dp[i] != INF)
                ans = min(ans, dp[i] + pp);
        }
        pp += p[i];
    }
    if (ans == INF)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("%I64d\n", ans);
    return 0;
}