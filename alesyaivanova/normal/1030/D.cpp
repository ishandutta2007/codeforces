#include <bits/stdc++.h>

#define int long long

using namespace std;

long long gcd(long long a, long long b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

signed main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long s = 2 * n * m;
    if (s % k != 0)
    {
        cout << "NO";
        return 0;
    }
    s /= k;
    int x = gcd(s, n);
    if (x * 2 <= n && (s / x) % 2 == 0)
        x *= 2;
    int y = s / x;
    if (y > m)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n0 0\n" << x << " 0\n0 " << y;
}