

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
int a[100];
int f(int x)
{
    int count = 0;
    while (x > 0)
    {
        x /= 10;
        count++;
    }
    return count;
}
long long f2 (long long x)
{
    long long y = 0;
    long long x1 = x;
    int l = f(x1) - 1;
    while (x1 > 0)
    {
        a[l--] = x1 % 10;
        x1 /= 10;
    }
    l = f(x);
    for(int i = 0; i < l; i++)
    {
        y = y * 10 + (9 - a[i]);
    }
    return x * y;
}
int main()
{
    long long l, r, n1, n2, k;
    cin >> l >> r;
    n1 = f(l);
    n2 = f(r);
    k = 5;
    for (int i = 1; i < n2; i++)
    {
        k *= 10;
    }
    if (r < k - 1)
    {
        cout << f2(r);
        return 0;
    }
    if (l <= k - 1)
    {
        cout << f2(k);
        return 0;
    }
    cout << f2(l);
    return 0;
}