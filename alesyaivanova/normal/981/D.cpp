#include <bits/stdc++.h>

using namespace std;

bool dp[50][50];
long long sum[50][50];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sum[0][0] = a[0];
    for (int i = 1; i < n; i++)
        sum[0][i] = sum[0][i - 1] + a[i];
    for (int e = 1; e < n; e++)
    {
        for (int i = e; i < n; i++)
            sum[e][i] = sum[0][i] - sum[0][e - 1];
    }
    long long cur = 0;
    for (long long q = (1ll << 60); q >= 1; q /= 2)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int e = 0; e < 50; e++)
                dp[i][e] = false;
        }
        cur += q;
        for (int i = 0; i < n; i++)
        {
            if ((sum[0][i] & cur) == cur)
                dp[0][i] = true;
        }
        for (int num = 1; num < k; num++)
        {
            for (int i = num; i < n; i++)
            {
                for (int e = num - 1; e < i; e++)
                {
                    if (dp[num - 1][e] && ((sum[e + 1][i] & cur) == cur))
                        dp[num][i] = true;
                }
            }
        }
        if (!dp[k - 1][n - 1])
            cur -= q;
    }
    cout << cur;
}