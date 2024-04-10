#include <iostream>

using namespace std;

static inline bool isprime(int x)
{
    if (x == 1) return false;
    for (int i = 2; i*i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

static inline bool ispalin(int x)
{
    int p = 1;
    while (p * 10 <= x) p *= 10;

    int q = 1;
    while (q < p)
    {
        if (x / p % 10 != x / q % 10)
            return false;
        p /= 10;
        q *= 10;
    }

    return true;
}

int main()
{
    int p, q;
    int n;

    cin >> p >> q;
    n = 0;

    int nprime = 0, npalin = 0;
    for (int i = 1; i <= 1179887 /* my solution for 42, 1 */; ++i)
    {
        if (isprime(i))
            nprime ++;
        if (ispalin(i))
            npalin ++;
        if (nprime * (long long)q <= p * (long long)npalin)
            n = i;
    }
    if (n == 0)
        cout << "Palindromic tree is better than splay tree" << endl;
    else
        cout << n << endl;

    return 0;
}