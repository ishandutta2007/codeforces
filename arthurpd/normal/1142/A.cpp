#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

#define inf 0x3f3f3f3f3f3f3f3fll

long long foomin(long long n, long long k, long long x)
{
    x = x + 2 * (k);
    x = x % (k);

    long long retv = inf;
    for (int i = 0; i <= 200000; i++)
    {
        long long l = x + i * k;
        if (l != 0)
        {
            retv = min(retv, n * k / gcd(n * k, l));
        }
    }

    return retv;
}

long long foomax(long long n, long long k, long long x)
{
    x = x + 2 * (k);
    x = x % (k);

    long long retv = -inf;
    for (int i = 0; i <= 200000; i++)
    {
        long long l = x + i * k;
        if (l != 0)
        {
            retv = max(retv, n * k / gcd(n * k, l));
        }
    }

    return retv;
}


/*long long foomin(long long n, long long k, long long x)
{
    x = x + 2 * (k);
    x = x % (k);
    long long y = k / gcd(k, x);
    
    return y;
    long long retv = inf;
    for (int i = n; i <= n; i++)
    {
        long long z = (i * y * k) % (n * k);
        retv = min(retv, y * ((n * k) / gcd(n * k, z)));
    }

    return retv;
}

long long foomax(long long n, long long k, long long x)
{
    x = x + 2 * (k);
    x = x % (k);
    long long y = k / gcd(k, x);
    
    return y * ((n * k) / gcd(n * k, y * k));
    long long retv = -inf;
    for (int i = 1; i <= 100000; i++)
    {
        long long z = (i * y * k) % (n * k);
        retv = max(retv, y * ((n * k) / gcd(n * k, z)));
    }

    return retv;
}
*/
int main(void)
{
    long long n, k, a, b;

    cin >> n >> k >> a >> b;
    cout << min(min(min(foomin(n, k, a + b), foomin(n, k, a - b)), foomin(n, k, - a - b)), foomin(n, k, - a + b)) << " ";
    cout << max(max(max(foomax(n, k, a + b), foomax(n, k, a - b)), foomax(n, k, - a - b)), foomax(n, k, - a + b)) << endl;
}