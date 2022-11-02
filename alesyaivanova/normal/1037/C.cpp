#include <bits/stdc++.h>

using namespace std;

int dp[1000010];

int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0])
        dp[0] = 0;
    else
        dp[0] = 1;
    if (n >= 2)
    {
        if (a[0] != b[0] && a[0] != a[1] && b[0] != b[1])
            dp[1] = 1;
        else
        {
            if (a[1] == b[1])
                dp[1] = dp[0];
            else
                dp[1] = dp[0] + 1;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i] == b[i])
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[i - 1] + 1;
        if (a[i] != a[i - 1] && a[i] != b[i] && b[i] != b[i - 1])
            dp[i] = min(dp[i], dp[i - 2] + 1);
    }
    cout << dp[n - 1];
}