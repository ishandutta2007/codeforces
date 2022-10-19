#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];

int l[N], r[N];

int dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        l[i] = r[i] = -1;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (l[a[i]] == -1)
            l[a[i]] = i;
        r[a[i]] = i;
    }
    int j = -1;
    int q = 0;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (l[i] == -1)
            continue;
        ++q;
        dp[i] = 1;
        if (j != -1)
        {
            if (r[j] < l[i])
                dp[i] = dp[j] + 1;
        }
        j = i;
        maxu = max(maxu, dp[i]);
    }
    printf("%d\n", q - maxu);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}