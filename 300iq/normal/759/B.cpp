#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int a[N];
ll dp[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        a[i] = t;
        dp[i] = dp[i - 1] + 20;
        int l = 0, r = i - 1;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (a[m] + 90 - 1 >= t)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        dp[i] = min(dp[i], (r > 0 ? dp[r - 1] : 0) + 50);
        l = 0, r = i - 1;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (a[m] + 1440 - 1 >= t)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        dp[i] = min(dp[i], (r > 0 ? dp[r - 1] : 0) + 120);
        printf("%lld\n", dp[i] - sum);
        sum += dp[i] - sum;
    }
}