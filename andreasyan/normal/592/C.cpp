#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

long long t, a, b;

int main()
{
    cin >> t >> a >> b;
    if (a > b)
        swap(a, b);
    if (a == 1)
    {
        long long ans = (t / b);
        cout << (ans / gcd(t, ans)) << '/' << (t / gcd(t, ans)) << endl;
        return 0;
    }
    long long g = gcd(a, b);
    long double bb = b;
    if (a / g > t / bb)
    {
        long long ans = min(t, a - 1);
        cout << (ans / gcd(t, ans)) << '/' << (t / gcd(t, ans)) << endl;
        return 0;
    }
    long long l = a / g * b;
    long long ans = (a - 1) + (t / l) * a;
    if ((t / l) * l + a - 1 > t)
        ans -= ((t / l) * l + a - 1 - t);
    cout << (ans / gcd(t, ans)) << '/' << (t / gcd(t, ans)) << endl;
    return 0;
}