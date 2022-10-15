#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;


const long double eps = 1e-9;

long double a, b, l, w;
long double ll, rr, cc;

bool cmp(long double a, long double b)
{
    return a < b || fabs(a - b) < eps;
}

long double F(long double x, long double y, long double angle)
{
    return sin(angle) * (y - (b - sin(angle) * x) / cos(angle)) + cos(angle) * x;
}

bool f(long double x, long double y)
{
    if (cmp(x, a) && cmp(y, b)) return true;
    if (!cmp(x, a) || !cmp(x, b)) return false;

    long double l = 0, r = M_PI / 2;
    while (l + eps < r)
    {
        long double
            lc = l + (r - l) / 3,
            rc = r - (r - l) / 3;
        if (F(x, y, lc) > F(x, y, rc))
            r = rc;
        else
            l = lc;
    }
    return cmp(F(x, y, (l + r) / 2), a);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> a >> b >> l;

    ll = 0;
    rr = l;
    while (ll + eps < rr)
    {
        cc = (ll + rr) / 2;

        if (f(l, cc) || f(cc, l))
            ll = cc;
        else
            rr = cc;
    }
    w = (ll + rr) / 2;
    if (cmp(w, 0))
        cout << "My poor head =(" << endl;
    else
    {
        cout.precision(8);
        cout << fixed << w << endl;
    }
    
    return 0;
}