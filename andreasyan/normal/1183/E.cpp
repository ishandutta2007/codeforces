#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
long long k;
char a[N];

long long dp[N][N][N][26];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            for (int q = 1; q <= d; ++q)
            {
                long long sum = 0;
                for (int i = 0; i < 26; ++i)
                {
                    sum += dp[l][r - 1][q - 1][i];
                    if (i == a[r] - 'a')
                        continue;
                    dp[l][r][q][i] = dp[l][r - 1][q][i];
                }
                if (q == 1)
                    ++sum;
                sum = min(sum, k);
                dp[l][r][q][a[r] - 'a'] = sum;
            }
        }
    }
    dp[1][n][0][0] = 1;
    long long ans = 0;
    for (int q = n; q >= 0; --q)
    {
        long long sum = 0;
        for (int i = 0; i < 26; ++i)
            sum += dp[1][n][q][i];
        sum = min(sum, k);
        if (sum >= k)
        {
            ans += (k * (n - q));
            k = 0;
            break;
        }
        else
        {
            ans += (sum * (n - q));
            k -= sum;
        }
    }
    if (k)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}