#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long

#define maxN 10011
#define inf (1LL << 50)

int n, i, j;
ll c;
ll p[maxN], s[maxN];

int ss, dd;
ll dp[2][maxN];



int main()
{
    //freopen("test.in", "r", stdin);

    scanf("%d%lld", &n, &c);
    for (i = 1; i <= n; i++) scanf("%lld", &p[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &s[i]);

    ss = 0; dd = 1;
    for (i = 0; i <= n; i++) dp[ss][i] = inf;
    dp[ss][0] = p[1];
    dp[ss][1] = s[1];

    for (i = 1; i < n; i++) {
        for (j = 0; j <= i + 1; j++) {
            dp[dd][j] = inf;
            if (j > 0)
                dp[dd][j] = min(dp[dd][j], dp[ss][j - 1] + s[i + 1]);

            if (j <= i)
                dp[dd][j] = min(dp[dd][j], dp[ss][j] + p[i + 1] + c * j);
        }
        swap(ss, dd);
    }

    ll ans = inf;
    for (i = 0; i <= n; i++) ans = min(ans, dp[ss][i]);
    printf("%lld", ans);

    return 0;
}