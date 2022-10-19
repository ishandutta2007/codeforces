#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

long long n, m, x, y, a, b;

bool stg(long long k)
{
    return (a * k) <= n && (b * k) <= m;
}

long long byn()
{
    long long l = 1, r = n;
    while ((r - l) > 3)
    {
        long long m = (l + r) / 2;
        if (stg(m))
            l = m;
        else
            r = m;
    }
    for (long long m = r; m >= l; --m)
        if (stg(m))
            return m;
}

int main()
{
    cin >> n >> m >> x >> y >> a >> b;
    long long gg = gcd(a, b);
    a /= gg;
    b /= gg;
    long long xx = byn() * a;
    long long yy = byn() * b;
    long long x1, x2, y1, y2;
    if (x + (xx / 2) > n)
    {
        x1 = (n - xx);
        x2 = n;
    }
    else if (x - (xx / 2 + xx % 2) < 0)
    {
        x1 = 0;
        x2 = xx;
    }
    else
    {
        x1 = x - (xx / 2 + xx % 2);
        x2 = x + (xx / 2);
    }

    if (y + (yy / 2) > m)
    {
        y1 = (m - yy);
        y2 = m;
    }
    else if (y - (yy / 2 + yy % 2) < 0)
    {
        y1 = 0;
        y2 = yy;
    }
    else
    {
        y1 = y - (yy / 2 + yy % 2);
        y2 = y + (yy / 2);
    }

    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    return 0;
}