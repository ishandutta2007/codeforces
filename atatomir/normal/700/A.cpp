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

int n, k, i;
double l, v1, v2;
double bound, need;

bool check(double limit) {
    int i;
    double pos, pos_gr, T, delta;
    double est;

    pos = T = 0;
    need = (l - v1 * limit) / (v2 - v1);

    for (i = 1; i <= k; i++) {
        if (T > limit) return false;

        pos_gr = T * v1;
        delta = (pos - pos_gr) / (v1 + v2);

        T += delta;
        pos = pos_gr = T * v1;

        T += need;
        pos += need * v2;
    }

    return T <= limit;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);

    bound = l / v1;
    k = (n + k - 1) / k;

    if (v1 >= v2) {
        printf("%.10lf", bound);
        return 0;
    }

    double l = 0.00;
    double r = bound;
    double mid;
    int steps = 60;

    while (steps--) {
        mid = (l + r) / 2.00;
        if (!check(mid))
            l = mid;
        else
            r = mid;
    }

    printf("%.10lf", (l + r) / 2.00);


    return 0;
}