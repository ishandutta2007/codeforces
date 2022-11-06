#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

const long long THR = 5000;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long n, l, r, k;
    scanf("%lld%lld%lld%lld", &n, &l, &r, &k);

    long long d = r - l + 1;
    while(d <= 0)
        d += n;

    if(k < d)
    {
        puts("-1");
        return 0;
    }

    long long res = -1;
    if(n < THR)
    {
        for(long long i = 0; i <= d; i++)
        {
            for(long long j = 0; j <= (n - d); j++)
            {
                long long t = k - (d + i);
                if(t == 0 || i > 0 && t == -1)
                {
                    res = max(res, i + j);
                    continue;
                }

                long long q = t / (n + i + j);
                long long t2 = t - q * (n + i + j);
                if(q >= 0 && (t2 == 0 || i > 0 && t2 == -1))
                {
                    res = max(res, i + j);
                    continue;
                }

                long long t3 = t - (q + 1) * (n + i + j);
                if(q + 1 >= 0 && (t3 == 0 || i > 0 && t3 == -1))
                {
                    res = max(res, i + j);
                    continue;
                }
            }
        }
    }
    else
    {
        long long s, g;
        s = max(0LL, (k / 2 - d) / n);
        g = max(s, (k - d) / n);

        for(long long i = s; i <= g; i++)
        {
            if(k < d + n * i)
                continue;

            if(k > 2 * (d + n * i))
                continue;

            if(i == 0)
            {
                res = max(res, min(d, k + 1 - d) + n - d);
                continue;
            }

            {
                long long t = k - (d + n * i);

                if(t >= 0)
                {
                    long long q = t / i;
                    long long r = t % i;

                    if(r <= d && 0 <= (q - r) && (q - r) <= n - d)
                        res = max(res, q);
                    else if(r <= d && (q - r) > n - d)
                    {
                        long long x = (q - r) - (n - d);

                        long long s = (x + i) / (i + 1);
                        long long q2 = q - s;

                        long long r2 = r + s * i;
                        if(0 <= r2 && r2 <= d && 0 <= (q2 - r2) && (q2 - r2) <= n - d)
                            res = max(res, q2);
                    }
                }
            }

            {
                long long t = k - (d + n * i);
                t -= i + 1;
                t++;

                if(t >= 0)
                {
                    long long q = t / i;
                    long long r = t % i;

                    if(r <= d - 1 && 0 <= (q - r) && (q - r) <= n - d)
                        res = max(res, q + 1);
                    else if(r <= d - 1 && (q - r) > n - d)
                    {
                        long long x = (q - r) - (n - d);

                        long long s = (x + i) / (i + 1);
                        long long q2 = q - s;

                        long long r2 = r + s * i;
                        if(r2 <= d - 1 && 0 <= (q2 - r2) && (q2 - r2) <= n - d)
                            res = max(res, q2 + 1);
                    }
                }
            }
        }
    }

    printf("%lld\n", res);
    return 0;
}