#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 5009;
int a[MAX_N];
int dp[MAX_N][MAX_N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1])
        {
            i--;
            n--;
        }
    }
    for (int l = n - 2; l >= 0; l--)
    {
        dp[l][l] = 0;
        dp[l][l + 1] = 1;
        for (int r = l + 2; r < n; r++)
        {
            dp[l][r] = min(dp[l + 1][r] + 1, dp[l][r - 1] + 1);
            if (a[l] == a[r])
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1);
        }
    }
    cout << dp[0][n - 1];
}