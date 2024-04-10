#include <cstdio>
#include <iostream>
#include <cmath>

#define sqr(x) ((x)*(x))

using namespace std;


int n, R, r;
long double l, x;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    cin >> n >> R >> r;

    if (r > R)
    {
        puts(n <= 0? "YES" : "NO");
        return 0;
    }

    if (2 * r > R)
    {
        puts(n <= 1? "YES" : "NO");
        return 0;
    }

    if (2 * r == R)
    {
        puts(n <= 2? "YES" : "NO");
        return 0;
    }


    l = sqrt((long double)(sqr(R - r) - sqr(r)));
    x = (R - r) * cos(M_PI / n);

    if (l > x || fabs(l - x) < 1e-11)
        puts("YES");
    else
        puts("NO");
    return 0;
}