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

#define maxN 21

int n, cnt, k, i, lim, st;
double aux[maxN], p[maxN];
double sum[1 << maxN], dp[1 << maxN], bits[1 << maxN];
double ans[maxN];


double comp(double x) {
    return 1.00 / (1.00 - x);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%lf", &aux[i]);
        if (aux[i] > 1e-9)
            p[++cnt] = aux[i];
    }

    lim = 1 << cnt;
    for (st = 0; st < lim; st++) {
        sum[st] = 0;

        for (i = 0; i < cnt; i++)
            if ( (st >> i) & 1 )
                sum[st] += p[i + 1], bits[st]++;
    }

    k = min(k, cnt);
    dp[0] = 1;
    for (st = 1; st < lim; st++) {
        if ((st & (st - 1)) == 0) {
            dp[st] = sum[st];
        } else {
            for (i = 0; i < cnt; i++) {
                if ( ((st >> i) & 1) == 0 ) continue;
                dp[st] += dp[st ^ (1 << i)] * p[i + 1] * comp(sum[st ^ (1 << i)]);
            }
        }

        if (bits[st] == k) {
            for (i = 0; i < cnt; i++) {
                if ( ((st >> i) & 1) == 0 ) continue;
                ans[i + 1] += dp[st];
            }
        }
    }

    cnt = 0;
    for (i = 1; i <= n; i++) {
        if (aux[i] < 1e-9)
            printf("0.00 ");
        else
            printf("%.15lf ", ans[++cnt]);
    }



    return 0;
}