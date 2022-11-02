#include <iostream>

using namespace std;

int main()
{
    long long k, d, t;
    cin >> k >> d >> t;
    long long e = (k + d - 1) / d;
    long long m = e * d - k;
    long long p = (2 * t) / (2 * k + m);
    double per = ((double) (2 * k + m)) / (2 * t);
    double mod = 1 - per * p;
    cout.precision(20);
    if (mod * t <= k)
    {
        cout << fixed << p * d * e + mod * t;
    }
    else
    {
        cout << fixed << p * d * e + k + (mod - ((double) k) / t) * (2 * t);
    }
}