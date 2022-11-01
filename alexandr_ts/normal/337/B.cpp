#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

long long nod (long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return nod (b, a % b);
}

int main()
{
    long long ans1, x1, ans, z, x, y, ma, mi, a, b, c, d, a1, b1, c1, d1;
    cin >> a >> b >> c >> d;
    a1 = a;
    b1 = b;
    c1 = c;
    d1 = d;
    if (a * d > c * b)
    {
        x = b * b * c * d;
        y = d * d;
    }
    else
    {
        x = a * a * c * d;
        y = c * c;
    }
    ans = a * b * y - x;
    ans1 = y * a * b;
    a1 = nod(ans, ans1);
    ans /= a1;
    ans1 /= a1;
    if (ans == 0)
        ans1 = 1;
    cout << ans << "/" << ans1;
    return 0;
}