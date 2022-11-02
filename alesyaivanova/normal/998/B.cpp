#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
int a[101];

int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int num = 0;
    if (a[0] % 2 == 0)
        num++;
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= b; k++)
        {
            dp[i][k] = dp[i - 1][k];
            int c = abs(a[i] - a[i - 1]);
            if (k >= c && num * 2 == i)
                dp[i][k] = max(dp[i][k], dp[i - 1][k - c] + 1);
        }
        if (a[i] % 2 == 0)
            num++;
    }
    int ma = 0;
    for (int i = 0; i <= b; i++)
        ma = max(ma, dp[n - 1][i]);
    cout << ma;
}