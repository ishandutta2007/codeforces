#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  
   long long d, d2, i, n, m, k, a[100000];
    cin >> n >> m >> k;
   for (i = 0; i < n; i++)
      cin >> a[i];
   if (n == 1)
    {
        d = m * k;
        if (d > a[0]) d= a[0];
        cout << d;
        return 0;
    }
    if (n % 2 == 0)
    {
        cout << 0;
        return 0;
    }
    d = a[0];
    for (i = 0; i < (n + 1) / 2; i++)
    {
        if (a[i * 2] < d)  d = a[i * 2];
    }
    d2 = m / ((n + 1) / 2) * k;
    if (d > d2) d = d2;
    cout << d;

    return 0;
}