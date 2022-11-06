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

pair<long long, long long> sor[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long n, s, x, a, b, i, c, r, e, t, p, q, k;
    scanf("%lld%lld", &n, &s);

    c = r = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &x, &a, &b);
        c += x;
        r += 1LL * x * b;
        sor[i] = { a - b, x };
    }

    sort(sor, sor + n);

    k = (c + s - 1) / s * s - c;
    t = 0;
    e = r;
    for(i = n - 1; i >= 0; i--)
    {
        p = sor[i].first;
        q = sor[i].second;

        if(p >= 0)
        {
            if(t >= q)
            {
                t -= q;
                r += 1LL * p * q;
                if(t <= k)
                    e = max(e, r);
                continue;
            }

            r += 1LL * p * t;
            q -= t;
            t = 0;

            r += 1LL * p * ((q / s) * s);
            q -= (q / s) * s;
            e = max(e, r);

            if(q)
            {
                r += 1LL * p * q;
                t = s - q;
                if(t <= k)
                    e = max(e, r);
            }
        }
        else
        {
            if(t > k)
            {
                if(t - k > q)
                {
                    r += 1LL * p * q;
                    t -= q;
                    continue;
                }
                r += 1LL * p * (t - k);
            }
            e = max(e, r);
            break;
        }
    }
    if(t <= k)
        e = max(e, r);

    printf("%lld", e);
    return 0;
}