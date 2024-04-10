#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1024;
long long a[N + 10];

long long f(long long k)
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

int main()
{
   long long res = 0;
    long long l, r;
    int i, r1, l1;
    cin >> l >> r;
    for (i = 0; i < N; i++)
    {
        a[i] = f(i + 1);
    }
    sort(a, a + N);
    for (i = 1; i < N; i++)
    {
        r1 = r;
        if (r > a[i])
            r1 = a[i];
        l1 = l;
        if (l <= a[i - 1])
            l1 = a[i - 1] + 1;
        if (r1 - l1 + 1 > 0)
            res += ((r1 - l1 + 1) * a[i]);
    }
    cout << res;
    return 0;
}