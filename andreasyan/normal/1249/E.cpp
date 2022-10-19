#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, c;
int a[N], pa[N];
int b[N], pb[N];

int dp[N];

int ans[N];
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i < n; ++i)
        pa[i] = pa[i - 1] + a[i];
    for (int i = 1; i < n; ++i)
        pb[i] = pb[i - 1] + b[i];
    int mina = dp[1] + pa[0];
    int minb = dp[1] + pb[0];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = min(pa[i - 1] + mina, pb[i - 1] + minb + c);
        mina = min(mina, dp[i] - pa[i - 1]);
        minb = min(minb, dp[i] - pb[i - 1]);
    }
    ans[n] = dp[n];
    int minu = dp[n] + pa[n - 1];
    for (int i = n - 1; i >= 1; --i)
    {
        minu = min(minu, dp[i] + pa[i - 1]);
        ans[i] = minu - pa[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}