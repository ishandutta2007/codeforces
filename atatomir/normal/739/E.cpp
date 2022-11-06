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

const int maxN = 2018;

int n, a, b, i;
double p[maxN], u[maxN];
pair<double, pair<int, int> > dp[maxN];
double last_mid;

template<typename tp>
void upd(tp& a, tp b) {
    a = max(a, b);
}

int check(double cost_A, double cost_B) {
    int i, j;
    double aux;

    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++) {
        aux = 1.00 - (1.00 - p[i + 1]) * (1.00 - u[i + 1]);

        upd(dp[i + 1], dp[i]);
        upd(dp[i + 1], mp(dp[i].first + p[i + 1] - cost_A, mp(dp[i].second.first + 1, dp[i].second.second)));
        upd(dp[i + 1], mp(dp[i].first + u[i + 1] - cost_B, mp(dp[i].second.first, dp[i].second.second + 1)));
        upd(dp[i + 1], mp(dp[i].first + aux - cost_A - cost_B, mp(dp[i].second.first + 1, dp[i].second.second + 1)));
    }

    return dp[n].second.first;
}

int big_check(double cost_B) {
    double lo = 0.00;
    double hi = 1.00;

    for (int iter = 1; iter <= 60; iter++) {
        double mid = (lo + hi) / 2.00;

        if (check(mid, cost_B) > a)
            lo = mid;
        else
            hi = mid;
    }

    double mid = hi;
    check(mid, cost_B);
    last_mid = mid;
    return dp[n].second.second;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &a, &b);
    for (i = 1; i <= n; i++) scanf("%lf", &p[i]);
    for (i = 1; i <= n; i++) scanf("%lf", &u[i]);

    double lo = 0.00;
    double hi = 1.00;

    for (int iter = 1; iter <= 50; iter++) {
        double mid = (lo + hi) / 2.00;

        if (big_check(mid) > b)
            lo = mid;
        else
            hi = mid;
    }

    double mid = hi;
    big_check(mid);
    printf("%.10lf", dp[n].first + last_mid * a + mid * b);


    return 0;
}