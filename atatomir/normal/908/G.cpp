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

#define maxN 711
#define mod 1000000007

int n, i, j;
char s[maxN];
ll poww[maxN], sum[maxN];
ll dp[2][maxN][2], ss, dd;
ll ans;

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void solve_with(int cf) {
    int i, j, k;

    memset(dp, 0, sizeof(dp));
    ss = 0; dd = 1;

    dp[ss][0][0] = 1;
    for (i = 1; i <= n; i++) {
        memset(dp[dd], 0, sizeof(dp[dd]));

        for (j = 0; j <= i; j++) {
            add(dp[dd][j + (s[i] - '0' < cf ? 1 : 0)][0], dp[ss][j][0]);
            for (k = 0; k < s[i] - '0'; k++)
                add(dp[dd][j + (k < cf ? 1 : 0)][1], dp[ss][j][0]);

            for (k = 0; k < 10; k++)
                add(dp[dd][j + (k < cf ? 1 : 0)][1], dp[ss][j][1]);
        }

        swap(ss, dd);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    //n = 100;
    //for (i = 1; i <= n; i++) s[i] = '8';

    poww[n] = 1;
    sum[n] = 1;
    for (i = n - 1; i > 0; i--) {
        poww[i] = (poww[i + 1] * 10) % mod;
        sum[i] = (sum[i + 1] + poww[i]) % mod;
    }

    for (int cf = 1; cf < 10; cf++) {
        solve_with(cf);

        for (i = 0; i <= n; i++) {
            ans += 1LL * (dp[ss][i][0] + dp[ss][i][1]) * sum[i + 1];
            ans %= mod;
        }
    }



    printf("%lld", ans);


    return 0;
}