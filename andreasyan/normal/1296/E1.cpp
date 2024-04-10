#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

int maxdp[26];
int dp[N];

int main()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = a[i] - 'a' + 1; j < 26; ++j)
        {
            dp[i] = max(dp[i], maxdp[j]);
        }
        ++dp[i];
        maxdp[a[i] - 'a'] = max(maxdp[a[i] - 'a'], dp[i]);
        ans = max(ans, dp[i]);
    }
    if (ans > 2)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
    {
        --dp[i];
        printf("%d", dp[i]);
    }
    printf("\n");
    return 0;
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d ", dp[i]);
    printf("\n");
    return 0;
}