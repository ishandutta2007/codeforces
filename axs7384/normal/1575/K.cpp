#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
inline int add (int x, int y) {return x + y >= mod ? x + y - mod : x + y;}
inline int mul (int x, int y) {return 1LL * x * y % mod;}
inline int qpm (int x, long long y) {
    int r = 1;
    while (y) {
        if (y & 1) r = mul(r, x);
        x = mul (x, x);
        y >>= 1;
    }
    return r;
}

long long n, m, r, c, k;
long long x1, x2, y1, y2;

signed main()
{
    scanf ("%lld %lld %lld %lld %lld", &n, &m, &k, &r, &c);
    scanf ("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    if (x1 > x2) {
        swap (x1, x2);
    }
    if (y1 > y2) {
        swap (y1, y2);
    }
    long long sx, sy, ex, ey;
    if (x1 + r - 1 < x2 || y1 + c - 1 < y2) {
        long long c1 = n * m, c2 = r * c;
        c1 -= c2 * 2;
        int ans = mul(qpm(k, c1), qpm(k, c2));
        printf ("%lld\n", ans);
    }
    else {
        sx = x2; sy = y2;
        ex = x1 + r - 1; ey = y1 + c - 1;
        long long len1 = ex - sx + 1, len2 = ey - sy + 1;
        long long c1 = n * m, c2 = r * c, c3 = len1 * len2;
        if (x1 == x2 && y1 == y2) {
            long long ans = qpm(k, c1);
            printf ("%lld\n", ans);
            return 0;
        }
        if (len1 * 2 > r && len2 * 2 > c) {
            // long long a = __gcd(len1, r), b = __gcd(len2, c);
            // long long A = ex - x1 + 1, B = ey - y1 + 1;
            int temp = qpm(k, c2 - c3);
            c1 = c1 - (c2 * 2 - c3);
            int ans = mul (qpm(k, c1), temp);
            printf ("%lld\n", ans);
        }
        else {
            c2 -= 2 * c3;
            c1 -= 3 * c3 + c2 * 2;
            int ans = mul(mul(qpm(k, c1), qpm(k, c2)), qpm(k, c3));
            printf ("%lld\n", ans);
        }
    }
    return 0;
}