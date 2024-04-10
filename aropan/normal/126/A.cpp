#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

long long t1, t0, t2, x1, x2;

long double ans;
long long a, b;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

//    cin >> t1 >> t0 >> t2 >> x1 >> x2;

    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    if (t1 == t0 && t2 == t0)
    {
        cout << x1 << " " << x2 << endl;
        return 0;
    }

    if (t1 == t0)
    {
        cout << x1 << " " << 0 << endl;
        return 0;
    }

    ans = 1e+60;

    for (long long y2 = 1; y2 <= x2; y2++)
    {
        long long y1 = (t2 * y2 - t0 * y2) / (t0 - t1);
        if (y1 > x1) y1 = x1;

        long double t = (long double)(t2 * y2 + t1 * y1) / (y2 + y1) - t0;
        if (t < 0) continue;

        if (t < ans || fabs(t - ans) < 1e-12 && a + b < y1 + y2)
        {
            ans = t;
            a = y1;
            b = y2;
        }
    }
    cout << a << " " << b << endl;

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}