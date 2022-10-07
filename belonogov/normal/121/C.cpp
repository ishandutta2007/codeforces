#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2048;
bool use[20];
long long a[N];

long long ff(long long k)
{
    long long res = 0;
    while(k > 1)
    {
        if (k % 2 == 0)
            res = res * 10 + 4;
        else
            res = res * 10 + 7;
        k /= 2;
    }
    return res;
}
int check (int d)
{
    for (int i = 0; i < N; i++)
        if (a[i] == d)
            return 1;

        return 0;
}

int main()
{
   long long n, k, f = 1, i, x, j, f1, d, t, kol, i1;
    int res = 0;
    cin >> n >> k;
    for (i = 0; i < N; i++)
    {
        a[i] = ff(i + 1);
    }
    sort(a, a + N);
    if (n <= 14)
    {
        for (i = 2; i <= n; i++)
            f *= i;
        if (k > f)
        {
            cout << -1;
            return 0;
        }
    }// check;
    f = 1;
    i = 1;
    while (f < k)
        f *= ++i;
    x = n - i;
    t = i;
    j = 1;
    while (a[j] <= x)
    {
        j++;
        res++;
    }
    while (i > 0)
    {
        f1 = f / i;
        d = (k + (f1 - 1)) / f1;
        kol = 0;
        for (i1 = 0; i1 < t; i1++)
        {
            if (! use[i1])
                kol++;
            if (kol == d)
                break;
        }
        use[i1] = true;
        k -= (d - 1) * f1;
        res += (check(i1 + x + 1) & check(n - i + 1));
        i--;
        f = f1;
    }
    cout << res;
    return 0;
}