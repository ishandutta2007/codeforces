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

#define maxN 111
#define lim 300000

int n, i, j, best;
double best_value;
double p[maxN];
double q[maxN];
double all;

double act[maxN];
double maybe[lim + 17];
double ans;

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("*.out","w",stdout);

    all = 1.00;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        p[i] /= 100.00;
        q[i] = 1.00 - p[i];

        act[i] = q[i];
        all *= p[i];
    }

    maybe[n] = all;
    for (i = n + 1; i <= lim; i++) {
        best_value = 0.00;

        for (j = 1; j <= n; j++) {
            double now = maybe[i - 1] / (1 - act[j]);
            now *= 1 - act[j] * q[j];

            if (now >= best_value) {
                best_value = now;
                best = j;
            }
        }

        maybe[i] = best_value;
        act[best] *= q[best];
    }

    ans = 0.00;
    for (i = n; i < lim; i++)
        ans -= maybe[i];
    ans += maybe[lim] * lim;

    printf("%.10lf", ans);

    return 0;
}