 #include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector <ll> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + x);
        int k = 0;
        if (i * 2 >= n)
        {
            dp[n] = min(dp[n], dp[i] + (i * 2 - n) * (ll) x + y);
        }
        while (i * 2 - k >= i && i * 2 - k <= n && dp[i * 2 - k] > dp[i] + y + x * (ll) k)
        {
            dp[i * 2 - k] = dp[i] + y + x * (ll) k;
            k++;
        }
    }
    cout << dp[n] << '\n';
}