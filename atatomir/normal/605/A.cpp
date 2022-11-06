#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n, i;
int v[maxN];
int wh[maxN];
int dp[maxN];
int ans = 1;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        wh[ v[i] ] = i;
    }

    for (i = 1; i <= n; i++) {
        dp[i] = 1;
        if (v[i] != 1 && wh[ v[i] - 1 ] < i)
            dp[i] = 1 + dp[ wh[v[i] - 1] ];
        ans = max(ans, dp[i]);
    }

    printf("%d", n - ans);

    return 0;
}