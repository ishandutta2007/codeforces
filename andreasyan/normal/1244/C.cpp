#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

long long n, p, w, d;

int main()
{
    cin >> n >> p >> w >> d;
    long long dd = (w * d) / gcd(w, d);
    for (long long y = 0; y * d <= dd; ++y)
    {
        long long pp = p - (y * d);
        if (pp >= 0 && pp % w == 0)
        {
            long long x = (pp / w);
            if (x + y <= n)
            {
                cout << x << ' ' << y << ' ' << (n - x - y) << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}