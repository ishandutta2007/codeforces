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

const double PI = acos(-1);

double R, x, y, xx, yy, xxx, yyy, xm, ym, rm;
double dx, dy;
double ang;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lf%lf%lf%lf%lf", &R, &x, &y, &xx, &yy);

    ll dist = (x - xx) * (x - xx) + (y - yy) * (y - yy);
    if (dist > R * R) {
        printf("%.20lf %.20lf %.20lf", x, y, R);
        return 0;
    }

    dx = xx - x;
    dy = yy - y;
    ang = atan2(dy, dx);

    xxx = x + R * cos(ang + PI);
    yyy = y + R * sin(ang + PI);

    xm = (xx + xxx) / 2.00;
    ym = (yy + yyy) / 2.00;
    rm = (xxx - xx) * (xxx - xx) + (yyy - yy) * (yyy - yy);
    rm = 0.50 * sqrt(rm);

    printf("%.20lf %.20lf %.20lf", xm, ym, rm);




    return 0;
}