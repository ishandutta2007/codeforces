#include <bits/stdc++.h>
using namespace std;

long double m, r;

int main()
{
    //cout << 200004.2426383 - 200002.4853317 << endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showbase);
    cout.precision(11);
    cin >> m >> r;
    long double d = sqrt(2.0) * r;
    long double ans = 0;
    for (long double i = 1; i <= m; ++i)
    {
        long double t = 0;
        t += r * m;

        t += r;
        if (i - 1 > 0)
            t += (d + r);
        if (i + 1 <= m)
            t += (d + r);

        long double n = (m - i - 1);
        if (n > 0)
            t += (((1 + 1 + (n - 1) * 2) * n) / 2 * r + n * 2 * d);
        n = i - 1 - 1;
        if (n > 0)
            t += (((1 + 1 + (n - 1) * 2) * n) / 2 * r + n * 2 * d);

        ans += (t / (m * m));
    }
    cout << ans << endl;
    return 0;
}