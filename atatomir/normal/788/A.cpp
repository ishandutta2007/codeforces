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

#define maxN 100011

int n, i;
ll a[maxN];
ll data[maxN];
ll dp[maxN];
ll ans = 0;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);

    n--;
    for (i = 1; i <= n; i++) {
        data[i] = a[i] - a[i + 1];
        if (data[i] < 0) data[i] = -data[i];
        if (i % 2 == 0) data[i] = -data[i];
    }

    for (i = 1; i <= n; i++) {
        dp[i] = max(0LL, dp[i - 1]) + data[i];
        ans = max(ans, dp[i]);
    }

    for (i = 1; i <= n; i++) data[i] = -data[i];

    for (i = 1; i <= n; i++) {
        dp[i] = max(0LL, dp[i - 1]) + data[i];
        ans = max(ans, dp[i]);
    }

    printf("%lld", ans);

    return 0;
}