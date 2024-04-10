#include <bits/stdc++.h>
using namespace std;

long long t1, t2, x1, x2, t0;

bool stg(long long y1, long long y2)
{
    return (t1 * y1 + t2 * y2) >= t0 * (y1 + y2);
}

long long byn(long long y1)
{
    long long l = 0, r = x2;
    if (y1 == 0)
        return r;
    if (t1 == t2 && t2 == t0)
        return r;
    while ((r - l) > 3)
    {
        long long y2 = (l + r) / 2;
        if (stg(y1, y2))
            r = y2;
        else
            l = y2;
    }
    for (long long y2 = l; y2 <= r; ++y2)
    {
        if (stg(y1, y2))
            return y2;
    }
    return -1;
}

int main()
{
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    long long ans1 = -1, ans2 = -1;
    for (long long y1 = 0; y1 <= x1; ++y1)
    {
        long long y2 = byn(y1);
        if (y2 == -1)
            continue;
        if (ans1 == -1 || ((t1 * y1 + t2 * y2) * (ans1 + ans2) < (y1 + y2) * (t1 * ans1 + t2 * ans2)) || ((t1 * y1 + t2 * y2) * (ans1 + ans2) == (y1 + y2) * (t1 * ans1 + t2 * ans2)) && (y1 + y2 > ans1 + ans2))
        {
            ans1 = y1;
            ans2 = y2;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}