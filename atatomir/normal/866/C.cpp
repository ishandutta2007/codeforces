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

#define maxN 55
#define maxR 5011

ll n, R, i, j, k;
ll F[maxN], S[maxN], P[maxN];

double dp[maxN][maxR];
double l, r, mid;
ll steps;

double check(double ini) {
    int i, j, k;
    ll act_f, act_s;
    double pp;

    dp[n][R + 1] = ini;
    for (i = 0; i <= R; i++)
        dp[n][i] = 0.00;

    for (i = n - 1; i > 0; i--) {
        act_f = F[i + 1];
        act_s = S[i + 1];
        pp = 0.01 * P[i + 1];

        dp[i][R + 1] = ini;
        for (j = 0; j <= R; j++) {
            dp[i][j] = 0.00;

            dp[i][j] += pp * (dp[i + 1][min(R + 1, j + act_f)] + act_f);
            dp[i][j] += (1.00 - pp) * (dp[i + 1][min(R + 1, j + act_s)] + act_s);
            dp[i][j] = min(dp[i][j], ini);
        }
    }

    dp[0][0] = 0.00;
    act_f = F[1];
    act_s = S[1];
    pp = 0.01 * P[1];

    i = j = 0;
    dp[i][j] += pp * (dp[i + 1][min(R + 1, j + act_f)] + act_f);
    dp[i][j] += (1.00 - pp) * (dp[i + 1][min(R + 1, j + act_s)] + act_s);

    return dp[0][0];
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> R;
    for (i = 1; i <= n; i++)
        cin >> F[i] >> S[i] >> P[i];

    l = 0.00; r = 100000000.00;
    steps = 60;

    while (steps-- > 0) {
        mid = (l + r) / 2.00;
        if (check(mid) > mid)
            l = mid;
        else
            r = mid;
    }

    mid = (l + r) / 2.00;
    printf("%.10lf", mid);


    return 0;
}