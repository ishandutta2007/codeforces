#include <bits/stdc++.h>
using namespace std;
const long double EPS = 0.0000000001;

long double x1, y1, x2, y2;
long double v, t;
long double vx, vy, wx, wy;

long double dist(long double x1, long double y1, long double x2, long double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool stg(long double tt)
{
    long double ux, uy;
    if (tt <= t)
    {
        ux = tt * vx;
        uy = tt * vy;
    }
    else
    {
        ux = t * vx + (tt - t) * wx;
        uy = t * vy + (tt - t) * wy;
    }
    ux += x1;
    uy += y1;
    return (dist(ux, uy, x2, y2) <= tt * v);
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> v >> t;
    cin >> vx >> vy;
    cin >> wx >> wy;
    long double l = 0, r = 1000000000;
    while ((r - l) > EPS)
    {
        long double m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    cout << l << endl;
    return 0;
}