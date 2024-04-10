#include <bits/stdc++.h>
using namespace std;

long long x, xx;

vector<long long> v;

int main()
{
    scanf("%lld", &x);
    xx = x;
    for (long long i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            long long u = 1;
            while (x % i == 0)
            {
                x /= i;
                u *= i;
            }
            v.push_back(u);
        }
    }
    v.push_back(x);
    long long aa = xx, bb = xx;
    for (int x = 0; x < (1 << v.size()); ++x)
    {
        long long a = 1;
        for (int i = 0; i < v.size(); ++i)
        {
            if ((x & (1 << i)))
                a *= v[i];
        }
        long long b = xx / a;
        if (max(a, b) < max(aa, bb))
        {
            aa = a;
            bb = b;
        }
    }
    printf("%lld %lld\n", aa, bb);
    return 0;
}