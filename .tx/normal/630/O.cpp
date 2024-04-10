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

void rot(ldouble& x, ldouble& y, ldouble ang) {
    ldouble xx = x * cos(ang) - y * sin(ang);
    ldouble yy = x * sin(ang) + y * cos(ang);
    x = xx;
    y = yy;
}

void pr(ldouble a, ldouble b) {
    printf("%.11f %.11f\n", (double) a, (double) b);
}

const ldouble PI = acosl(-1.0);

int main() {
    ldouble px, py, vx, vy, a, b, c, d;
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    ldouble t = sqrt(vx * vx + vy * vy);
    vx /= t;
    vy /= t;
    pr(px + vx * b, py + vy * b);
    rot(vx, vy, PI / 2);
    pr(px + vx * a / 2, py + vy * a / 2);
    ldouble tx = 0, ty = 0;
    pr(tx = px + vx * c / 2, ty = py + vy * c / 2);
    rot(vx, vy, PI / 2);
    tx = tx + vx * d;
    ty = ty + vy * d;
    pr(tx, ty);
    rot(vx, vy, PI / 2);
    tx = tx + vx * c;
    ty = ty + vy * c;
    pr(tx, ty);
    rot(vx, vy, PI / 2);
    tx = tx + vx * d;
    ty = ty + vy * d;
    pr(tx, ty);
    rot(vx, vy, -PI / 2);
    pr(px + vx * a / 2, py + vy * a / 2);

    return 0;
}