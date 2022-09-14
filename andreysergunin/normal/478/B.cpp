#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long long n, m, t, s, kmin, kmax;
    cin >> n >> m;
    kmax = (n - m + 1) * (n - m) / 2;
    if (n % m == 0)
    {
        t = n / m;
        kmin = m * t * (t - 1) / 2;
    }
    else
    {
        t = n / m;
        s = n - n / m * m;
        kmin = s * (t + 1) * t / 2 + (m - s) * t * (t - 1) / 2;
    }
    cout << kmin << ' ' <<  kmax;

}