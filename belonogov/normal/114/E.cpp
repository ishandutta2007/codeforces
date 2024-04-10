#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
const int s = 2e4;
int primes[s], count = 0, res = 0;
bool a[s];

int main()
{
   int l, r, i, j, k, d;
    cin >> l >> r;
    memset(a, true, sizeof a);
    a[0] = a[1] = false;
    for (i = 2; i < s; i++)
        if (a[i])
        {
            primes[count++] = i;
            for (j = i * i; j < s; j+=i)
                a[j] = false;
        }
    for (i = 0; i < s; i++)
        if (a[i] && i >= l && i <= r && i % 4 == 1)
            res++;
    k = r / s + 1;
    for (i = 1; i < k; i++)
    {
        memset(a, 1, sizeof a);
        for (j = 0; j < count; j++)
        {
            d = ((i * s + primes[j] - 1) / primes[j] * primes[j]);
            while (d < s * (i + 1))
            {
                a[d % s] = false;
                d += primes[j];
            }
        }
        for (j = 0; j < s; j++)
            if (a[j] && j + s * i >= l && j + s * i <= r && (j + s * i) % 4 == 1)
                res++;
    }
    if (l <= 2 && r >= 2)
        res++;
    cout << res;
    return 0;
}