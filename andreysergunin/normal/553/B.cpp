#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    long long l;
    cin >> n >> l;
    l--;
    long long dp[MAXN];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    int k = n;
    int ans[MAXN];
    for ( ; k > 0; )
    {
        if (dp[k - 1] > l)
        {
            ans[n - k] = n - k;
            k -= 1;
        }
        else
        {
            ans[n - k] = n - k + 1;
            ans[n - k + 1] = n - k;
            l -= dp[k - 1];
            k -= 2;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << endl;
}