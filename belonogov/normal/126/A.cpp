#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 1e6 + 10;
const long double eps = 1e-6;
const int INF = 1e8;
struct asd
{
    long double t;
    int y1, y2;
};

asd a[MAXN];
int x1, x2, t1, t2, t0;

long double mod(long double x)
{
    if (x > 0)
        return x;
    else
        return -x;
}

bool operator < (asd a, asd b)
{
    if (mod(a.t - b.t) > eps)
        return a.t < b.t;
    else
        return (a.y1 + a.y2) > (b.y1 + b.y2);

}

long double f(long double y1, long double y2)
{
    if (y1 == 0 && y2 == 0)
        return INF;
    return ((y1 * t1) + (y2 * t2)) / (y1 + y2);
}

asd tr(int k)
{
    int l, r;
    long double x, xr;
    asd z1;
    l = 0;
    r = x2;
    z1.y1 = k;
    while (l + 1 < r)
    {
        x = f(k, (l + r) / 2) - t0;
        xr = f(k,  r) - t0;
        if (! (mod(x - xr) < eps) && x + eps > 0)
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    z1.t = f(k, r) - t0;
    if (z1.t < 0)
        z1.t = INF;
    z1.y2 = r;
    return z1;

}

int main()
{
    int i;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if (t0 == t2)
    {
        if (t1 ==  t2)
            cout << x1 << " " << x2;
        else
            cout << 0 << " " << x2;
        return 0;
    }
    if (t0 == t1)
    {
        cout << x1 << " " << 0;
        return 0;
    }
    for (i = 0; i <= x1; i++)
    {
        a[i] = tr(i);
    }
    sort(a, a + x1 + 1);
    cout << a[0].y1 << " " <<a[0].y2;

    return 0;
}