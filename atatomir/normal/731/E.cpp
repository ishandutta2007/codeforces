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

#define maxN 200011

ll n, i;
ll sum[maxN];
ll dp[maxN];

ll best;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
    }

    dp[n + 1] = 0;
    best = sum[n] - dp[n + 1];

    for (i = n; i > 0; i--) {
        dp[i] = best;
        best = max(best, sum[i - 1] - dp[i]);
    }

    printf("%lld", dp[2]);




    return 0;
}