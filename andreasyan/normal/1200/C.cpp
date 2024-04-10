#include <bits/stdc++.h>
using namespace std;

int q;
long long n, m;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    long long x = n / gcd(n, m);
    long long y = m / gcd(n, m);
    while (q--)
    {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        long long s, e;
        if (sx == 1)
            s = (sy - 1) / x;
        else
            s = (sy - 1) / y;
        if (ex == 1)
            e = (ey - 1) / x;
        else
            e = (ey - 1) / y;
        if (s == e)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}