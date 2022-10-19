#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m, k;
int a[N];

int q[N];

long long p[N];

long long dp[N];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    n = k;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > n)
            continue;
        q[x] = max(q[x], y);
    }

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = p[i];
        for (int j = 1; j <= i; ++j)
        {
            dp[i] = min(dp[i], dp[i - j] + p[i] - p[i - j + q[j]]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}