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

long long r = -1;

void v(long long t)
{
    if(r == -1)
        r = t;
    else
        r = min(r, t);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    bool u;
    int f, t, t0, a1, t1, p1, a2, t2, p2, i;
    long long x, y, k, q, k1, k2;
    scanf("%d%d%d", &f, &t, &t0);
    scanf("%d%d%d", &a1, &t1, &p1);
    scanf("%d%d%d", &a2, &t2, &p2);
    
    if(t1 >= t0 && t2 >= t0)
    {
        if(1LL * f * t0 > t)
            printf("-1");
        else
            printf("0");
        return 0;
    }

    u = 0;
    if(t1 >= t0)
        u = 1;
    else if(t2 >= t0)
    {
        u = 1;
        a2 = a1;
        t2 = t1;
        p2 = p1;
    }

    for(i = 0;; i++)
    {
        if(u && i)
            break;

        if(1LL * a1 * i >= f)
        {
            if(1LL * f * t1 <= t)
                v(1LL * p1 * i);
            break;
        }

        x = t - 1LL * a1 * i * t1;
        if(x < 0)
            continue;

        y = f - 1LL * a1 * i;

        if(1LL * y * t2 > x)
            continue;

        k1 = y * t0 - x;
        k2 = 1LL * a2 * (t0 - t2);
        if(k1 < 0)
            k = 0;
        else
            k = (k1 + k2 - 1) / k2;

        k = max(k, 0LL);
        q = 1LL * k * a2;
        if(q >= y)
        {
            if(1LL * y * t2 <= x)
                v(1LL * p1 * i + 1LL * p2 * k);
        }
        else
        {
            if(q * t2 + (y - q) * t0 <= x)
                v(1LL * p1 * i + 1LL * p2 * k);
        }
    }

    if(!u)
    {
        swap(a1, a2);
        swap(t1, t2);
        swap(p1, p2);
        for(i = 0;; i++)
        {
            if(u && i)
                break;

            if(1LL * a1 * i >= f)
            {
                if(1LL * f * t1 <= t)
                    v(1LL * p1 * i);
                break;
            }

            x = t - 1LL * a1 * i * t1;
            if(x < 0)
                continue;

            y = f - 1LL * a1 * i;

            if(1LL * y * t2 > x)
                continue;

            k1 = y * t0 - x;
            k2 = 1LL * a2 * (t0 - t2);
            if(k1 < 0)
                k = 0;
            else
                k = (k1 + k2 - 1) / k2;

            k = max(k, 0LL);
            q = 1LL * k * a2;
            if(q >= y)
            {
                if(1LL * y * t2 <= x)
                    v(1LL * p1 * i + 1LL * p2 * k);
            }
            else
            {
                if(q * t2 + (y - q) * t0 <= x)
                    v(1LL * p1 * i + 1LL * p2 * k);
            }
        }
    }
    printf("%lld", r);
    return 0;
}