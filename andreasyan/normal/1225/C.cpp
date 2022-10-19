#include <bits/stdc++.h>
using namespace std;

long long n, p;

int main()
{
    cin >> n >> p;
    for (long long q = 0; q <= 60; ++q)
    {
        long long x = n - p * q;
        if (x < 0)
            x *= (-1);
        long long m = 0;
        while (x)
        {
            if (x % 2 == 1)
                ++m;
            x /= 2;
        }
        x = n - p * q;
        if (m <= q && q <= x)
        {
            cout << q << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}