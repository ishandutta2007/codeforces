#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 20000011
#define inf (1LL << 60)

int n, i, len;
ll x, y;
ll dp[maxN];

int main()
{
    scanf("%d%lld%lld", &n, &x, &y);


    dp[1] = 1;
    dp[2] = min(2 * x, x + y);

    /*for (len = 2; len < n; len <<= 1) {
        int lim = 2 * len;

        for (i = len + 1; i <= lim; i++) dp[i] = inf;
        for (i = len + 2; i <= 2 * len; i += 2)
            dp[i] = y + dp[i / 2];
        for (i = len + 1; i <= lim; i++)
            dp[i] = min(dp[i], dp[i - 1] + x);
        for (i = lim - 1; i > len; i--)
            dp[i] = min(dp[i], dp[i + 1] + x);
    }*/

    for (i = 3; i <= n; i += 2) {
        dp[i + 1] = min(x * (i + 1), y + dp[ (i + 1) / 2 ]);
        dp[i] = min(dp[i - 1] + x, dp[i + 1] + x);
    }

    printf("%lld", dp[n]);


    return 0;
}