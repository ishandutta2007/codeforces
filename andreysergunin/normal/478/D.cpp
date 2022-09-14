#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;


int main()
{
    long a, b, h, k, l, p, maxh, t;
    long f[400001], g[400001];
    long s[1000];
    p = 1000000007;
    cin >> a >> b;
    maxh = 0;
    while ((maxh + 1) * (maxh + 2) / 2 <= a + b)
        maxh++;
    s[0] = a + b - maxh * (maxh + 1) / 2;
    for (t = 0; t <= s[0]; t++)
        f[t] = 1;
    for (h = 1; h <= maxh; h++)
    {
        s[h] = a + b - maxh * (maxh + 1) / 2 + h * (h + 1) / 2;

        for (t = 0; t <= s[h]; t++)
        {
            g[t] = 0;
            if (t - h >= 0 && t - h <= s[h - 1])
                g[t] = (g[t] + f[t - h]) % p;
            if (s[h] - t - h >= 0 && t <= s[h - 1])
                g[t] = (g[t] + f[t]) % p;
        }
        for (t = 0; t <= s[h]; t++)
            f[t] = g[t];
    }

    cout << f[a];
    return 0;
}