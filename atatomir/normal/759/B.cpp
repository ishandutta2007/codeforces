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


const int sm = 90;
const int cost_sm = 50;
const int bg = 1440;
const int cost_bg = 120;

int n, i, psm, pbg;
ll t[maxN];
ll dp[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &t[i]);

    psm = pbg = 1;
    for (i = 1; i <= n; i++) {
        while (t[psm] + sm - 1 < t[i]) psm++;
        while (t[pbg] + bg - 1 < t[i]) pbg++;

        dp[i] = min(dp[i - 1] + 20, min(dp[psm - 1] + cost_sm, dp[pbg - 1] + cost_bg));
        printf("%lld\n", dp[i] - dp[i - 1]);
    }

    return 0;
}