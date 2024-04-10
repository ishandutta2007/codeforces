#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long double a, b;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    int test;
    cin >> test;
    while (test--)
    {
        cin >> a >> b;

        if (b < 1e-5)
        {
            printf("%.10lf\n", 1.0);
            continue;
        }

        if (a < 1e-5)
        {
            printf("%.10lf\n", 0.5);
            continue;
        }

        long double x = min(a / 4, b);
        long double y = 4 * x;
        printf("%.10lf\n", (double)((y * x * 0.5 + (a - y) * b + a * b) / (a * b * 2)));
    }

    return 0;
}