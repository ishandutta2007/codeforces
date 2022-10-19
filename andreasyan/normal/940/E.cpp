#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
int a[N];

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
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
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
    return min(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

long long dp[N];

int main()
{
    long long sum = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    bil(1, n, 1);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        if (i - k + 1 >= 1)
            dp[i] = max(dp[i], dp[i - k] + qry(1, n, i - k + 1, i, 1));
    }
    cout << sum - dp[n] << endl;
    return 0;
}