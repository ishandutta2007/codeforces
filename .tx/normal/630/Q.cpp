#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

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

using namespace std;

const ldouble PI = acosl(-1.0);

ldouble v(ldouble n, ldouble a) {
    ldouble r = a / (2 * sin(2 * PI / (2 * n)));
    ldouble h = sqrt(a * a - r * r);
    return h * n * a * a / (12 * tan(PI / n));
}

int main() {
    sciiid(l1, l2, l3);
    printf("%.11f", (double) (v(3, l1) + v(4, l2) + v(5, l3)));

    return 0;
}