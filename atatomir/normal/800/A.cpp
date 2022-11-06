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
ll p, a[maxN], b[maxN];

bool check(double tm) {
    double sum = 0;
    int i;

    for (i = 1; i <= n; i++) {
        sum += max(0.00, 1.00 * a[i] - (1.00 * b[i] / tm));
    }

    return sum <= 1.00 * p;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%lld", &n, &p);
    for (i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &b[i]);

    double le = 0.00;
    double ri = 1e20;
    int steps = 100;
    double mid;

    while (steps--) {
        mid = (le + ri) / 2.00;
        if (check(mid))
            le = mid;
        else
            ri = mid;
    }

    mid = (le + ri) / 2.00;
    if (mid > 1e18) {
        printf("-1");
        return 0;
    }

    printf("%.10lf", mid);


    return 0;
}