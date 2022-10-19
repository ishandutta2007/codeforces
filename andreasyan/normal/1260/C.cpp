#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long r, b, k;
        cin >> r >> b >> k;
        if (r > b)
            swap(r, b);
        long long g = gcd(r, b);
        r /= g;
        b /= g;
        if ((b - 1) / r + !!((b - 1) % r) >= k)
        {
            cout << "REBEL" << endl;
        }
        else
        {
            cout << "OBEY" << endl;
        }
    }
    return 0;
}