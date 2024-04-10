#include <bits/stdc++.h>
using namespace std;
const int N = 3003, M = 1000000007;
char u[7][7] =
{
    "0011",
    "0101",
    "1110",
    "1111"
};
 
int n;
char a[N];
 
int dp[N];
 
int z[N];
 
int dpp[N];
 
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %c", &a[i]);
        reverse(a + 1, a + i + 1);
        dp[0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            dp[j] = 0;
            if (i >= 1)
                dp[j] = (dp[j] + dp[j - 1]) % M;
            if (i >= 2)
                dp[j] = (dp[j] + dp[j - 2]) % M;
            if (i >= 3)
                dp[j] = (dp[j] + dp[j - 3]) % M;
            if (j >= 4)
            {
                bool z = false;
                for (int ii = 0; ii < 4; ++ii)
                {
                    bool zz = true;
                    for (int k = j - 3; k <= j; ++k)
                    {
                        if (a[k] != u[ii][j - k])
                        {
                            zz = false;
                            break;
                        }
                    }
                    if (zz)
                    {
                        z = true;
                        break;
                    }
                }
                if (!z)
                    dp[j] = (dp[j] + dp[j - 4]) % M;
            }
        }
        memset(z, 0, sizeof z);
        int k, r = 1;
        for (int j = 2; j <= i; ++j)
        {
            if (r >= j)
            {
                z[j] = z[k - j];
            }
            while (a[z[j] + 1] == a[j + z[j]])
                ++z[j];
            if (z[j] > r)
            {
                r = z[j];
                k = i;
            }
        }
        int maxu = 0;
        for (int j = 2; j <= i; ++j)
            maxu = max(maxu, z[j]);
        dpp[i] = dpp[i - 1];
        for (int j = maxu + 1; j <= i; ++j)
            dpp[i] = (dpp[i] + dp[j]) % M;
        printf("%d\n", dpp[i]);
        reverse(a + 1, a + i + 1);
    }
    return 0;
}