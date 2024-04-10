#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
const long long INF = 1e9;
long long f (long long a)
{
    if (a > 0)
        return a;
    else
        return -a;
}

long long f1 (long long a, long long b)
{
    if (a >= 0)
        return a / b;
    else
        return a / b - 1;
}

int main()
{
   long long  a, b, x1, y1, x2, y2, p1, p2, s1, s2, r1, r2;
    cin >> a >> b  >> x1 >> y1 >> x2 >> y2;
    a *= 2;
    b *= 2;
/*    if (a * b > INF)
        d = a * b;
    else
        d = ((long long)(1000 * INF / (a * b))) * (a * b);
    a *= 2;
    b *= 2;
  *  x1 += d;
    x2 += d;
   */
    p1 = f1((x1 - y1), b);
    p2 = f1((x2 - y2), b);
    s1 = f1((x1 + y1), a);
    s2 = f1((x2 + y2), a);
    r1 = f(s1 - s2);
    r2 = f(p1 - p2);
    cout << max(r1, r2);
    return 0;
}
//417851343