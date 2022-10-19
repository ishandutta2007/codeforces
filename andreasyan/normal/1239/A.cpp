#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1000000007;

int n, m;

int dp[N];

int main()
{
    scanf("%d%d", &n, &m);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= max(n, m); ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % M;
    printf("%d\n", ((((dp[n] + dp[n]) % M) + ((dp[m] + dp[m]) % M)) % M - 2 + M) % M);
    return 0;
}