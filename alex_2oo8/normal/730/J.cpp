#include <bits/stdc++.h>

using namespace std;

const int MX = 100;

int a[MX], b[MX];
pair<int, int> dp[MX + 1][MX * MX + 1];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 100 * (i + 1); j++) dp[i + 1][j] = j <= 100 * i ? dp[i][j] : make_pair(n + 1, 0);
        for (int j = 0; j <= 100 * i; j++) dp[i + 1][j + b[i]] = min(dp[i + 1][j + b[i]], make_pair(dp[i][j].first + 1, dp[i][j].second - a[i]));
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    pair<int, int> ans = dp[n][sum];
    for (int i = sum; i <= n * 100; i++) ans = min(dp[n][i], ans);

    printf("%d %d\n", ans.first, sum + ans.second);

    return 0;
}