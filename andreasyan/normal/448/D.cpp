#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

long long stg(long long x)
{
    long long kk = 0;
    for (int i = 1; i <= n; ++i)
    {
        kk += min(m, x / i);
    }
    return kk;
}

long long byn()
{
    long long l = 1, r = n * m;
    while ((r - l) > 4)
    {
        long long mid = (l + r) / 2;
        if (stg(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    for (long long mid = l; mid <= r; ++mid)
    {
        if (stg(mid) >= k)
            return mid;
    }
}

int main()
{
    cin >> n >> m >> k;
    cout << byn() << endl;
    return 0;
}