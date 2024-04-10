#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

#define sqr(x) ((x)*(x))
#define ang(x) ((x) * M_PI / 180)

using namespace std;

const long double e = 1e-2;

int k;
long double R, r, l;
long double x, y, xl, yl, xr, yr;
long double a, b, c, S;

long double COS[12], SIN[12];


bool check(long double x, long double y)
{
    long double s = 0;
    for (int i = 0; i < 12; i += 2)
        s = max(s, sqr(x + COS[i]) + sqr(y + SIN[i]));

    return s <= l + r;
}


bool end(long double x, long double y)
{
    long double s = 1e+60;
    for (int i = 0; i < 12; i += 2)
        s = min(s, sqr(x + COS[i]) + sqr(y + SIN[i]));
    return s > S;
}
               
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    R = 1;
    r = sqrt(sqr(R) - sqr(0.5));

    for (int i = 0; i < 12; i++)
    {
        COS[i] = cos(ang(i * 30));
        SIN[i] = sin(ang(i * 30));
    }

//    printf("%.20lf\n", r);

    scanf("%d", &k);
    l = k;
    l *= l;
    S = k + 3;
    S *= S;

    x = (k + 2) / 3 * 3 * COS[2];
    y = (k + 2) / 3 * 3 * SIN[2];

    xl = xr = x;
    yl = yr = y;

    long long ans = 0;
    do
    {
        long double s;

        s = y * xr - x * yr;
        while (s > 0 && abs(s) > e && !check(xr, yr))
        {
            xr += 2 * r * COS[5];
            yr += 2 * r * SIN[5];
            s = y * xr - x * yr;
        }

        while (check(xr, yr))
        {
            xr -= 2 * r * COS[5];
            yr -= 2 * r * SIN[5];
        }
        
        s = y * xl - x * yl;
        while (s < 0 && abs(s) > e && !check(xl, yl))
        {
            xl += 2 * r * COS[11];
            yl += 2 * r * SIN[11];
            s = y * xl - x * yl;
        }

        while (check(xl, yl))
        {
            xl -= 2 * r * COS[11];
            yl -= 2 * r * SIN[11];
        }
/*
        printf("%.20lf %.20lf\n", xl, yl);
        printf("%.20lf %.20lf\n", xr, yr);
        printf("\n");
        fflush(stdout);
//*/

        long double L = sqrt(sqr(xl - xr) + sqr(yl - yr));
        ans += max((long long)((L + r) / (2 * r)) - 1, 0LL);
        
        xl += 2 * r * COS[7];
        yl += 2 * r * SIN[7];

        xr += 2 * r * COS[9];
        yr += 2 * r * SIN[9];
    } while (!end(xr, yr) || !end(xl, yl));

    cout << ans << endl;
    return 0;
}