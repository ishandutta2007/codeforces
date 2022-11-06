#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 200011

int n, i;
double vv[maxN];
double dp[maxN];

double abss(double x) {
    if (x < 0) return -x;
    return x;
}

double test(double x) {
    for (int i = 1; i <= n; i++) vv[i] -= x;

    double aux = 0.00;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(vv[i], dp[i-1] + vv[i]);
        aux = max(aux, abss(dp[i]));
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = min(vv[i], dp[i-1] + vv[i]);
        aux = max(aux, abss(dp[i]));
    }

    for (int i = 1; i <= n; i++) vv[i] += x;

    return aux;
}

int main()
{
    //freopen("input.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lf", &vv[i]);

    double l = -10000.00;
    double r = 10000.00;
    double m1, m2;

    int steps = 100;

    while (steps > 0) {
        steps--;
        m1 = l + ((r - l) / 3);
        m2 = m1 + ((r - l) / 3);

        if ( test(m1) < test(m2) )
            r = m2;
        else
            l = m1;
    }

    double ans = test( (l + r) / 2.00 );

    printf("%.10lf\n", ans);

    //for (double eps = 0.1; eps <= 40; eps += 0.1) cerr << test(eps) << '\n';

    return 0;
}