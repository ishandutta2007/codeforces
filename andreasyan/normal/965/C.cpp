#include <bits/stdc++.h>
using namespace std;

long long n, k, rr, D;

long long q(long long x)
{
    long long h = (n / x);
    return (h / k + !!(h % k)) * x;
}

bool stg(long long x)
{
    long long h = (n / x);
    return (h / k + !!(h % k)) <= D;
}

long long ll;
void byn()
{
    long long l = 1, r = rr;
    while ((r - l) > 3)
    {
        long long m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    for (long long m = l; m <= r; ++m)
    {
        if (stg(m))
        {
            ll = m;
            return;
        }
    }
}

long long d;
bool stg1(long long x)
{
    long long h = (n / x);
    return (h / k + !!(h % k)) >= d;
}

long long ans;
void byn1()
{
    long long l = ll, r = rr;
    while ((r - l) > 3)
    {
        long long m = (l + r) / 2;
        if (stg1(m))
            l = m;
        else
            r = m;
    }
    for (long long m = r; m >= l; --m)
    {
        if (stg1(m))
        {
            ans = max(ans, q(m));
            break;
        }
    }
}

int main()
{
    cin >> n >> k >> rr >> D;
    byn();
    for (d = 0; d <= D; ++d)
        byn1();
    cout << ans << endl;
    return 0;
}