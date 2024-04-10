#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;
typedef double my_dbl;

#define double ldouble

using namespace std;

double p_min[111111];
double p_max[111111];
double ans1[111111];
double ans2[111111];

double m_sqrt(double x) {
    double l = 0, r = 10;
    for (int i = 0; i < 50; i++) {
        double m = (l + r) / 2;
        if (m * m <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

double solve(double a, double b, double c) {
    double d = sqrt(b * b - 4 * a * c);
    if (d != d) {
        d = 0;
    }
    return max((-b + d) / 2 / a, (-b - d) / 2 / a);
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        my_dbl x;
        scanf("%lf", &x);
        p_max[i] = x;
    }
    for (int i = 0; i < n; i++) {
        my_dbl x;
        scanf("%lf", &x);
        p_min[i] = x;
    }

    double a1 = 0;
    double a2 = 0;

    for (int i = 0; i < n; i++) {
        double c1 = p_min[i];
        double c2 = p_max[i];
        double x1 = solve(-1, c1 + c2 - a1 + a2, c1 * a1 + c2 * a1 - c2);
        double x2 = c1 + c2 - x1;
        ans1[i] = x1;
        ans2[i] = x2;
        a1 += x1;
        a2 += x2;
    }

    for (int i = 0; i < n; i++) {
        printf("%.20lf ", (my_dbl) ans2[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%.20lf ", (my_dbl) ans1[i]);
    }


    return 0;
}