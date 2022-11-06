#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

long long arr[100010];
long long n, m, a, d;

long long up(long long x)
{
    if(x % a)
        return (x / a + 1) * a;
    return x;
}

long long down(long long x)
{
    return x / a * a;
}

long long dv(long long x, long long y)
{
    return (x + y - 1) / y;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i;
    long long r, t, c, x, g;
    scanf("%lld%lld%lld%lld", &n, &m, &a, &d);
    for(i = 0; i < m; i++)
        scanf("%lld", &arr[i]);

    arr[m++] = a*n;
    sort(arr, arr + m);

    t = 0;
    r = 0;
    for(i = 0; i < m; i++)
    {
        c = arr[i];
        if(c <= t)
            continue;

        g = min(n*a, down(c));

        if(t < g)
        {
            t = down(t);

            if(d % a == 0)
            {
                x = dv((g - t) / a, d / a + 1);
                r += x;
                t += a + d + (d + a) * (x - 1);
            }
            else
            {
                x = dv((g - t) / a, down(d) / a + 1);
                r += x;
                t += a + d + up(d) * (x - 1);
            }
        }

        if(c <= t)
            continue;

        r++;
        t = c + d;
    }
    printf("%lld", r);
    return 0;
}