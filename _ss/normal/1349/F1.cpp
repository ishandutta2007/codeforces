#include<bits/stdc++.h>

using namespace std;
const int N = 5e3 + 10, mod = 998244353;
long long dp[N][N], n, ans[N];

int main()
{
    cin >> n;
    dp[1][1] = ans[1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (i - j + 1)) % mod;
            ans[j] = (ans[j] * i + dp[i][j]) % mod;
        }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    return 0;
}