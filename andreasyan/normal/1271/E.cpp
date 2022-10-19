#include <bits/stdc++.h>
using namespace std;

long long n, k;

bool stg(long long x)
{
    long long q = 0;
    long long qq;
    if (x % 2 == 0)
        qq = 2;
    else
        qq = 1;
    while (1)
    {
        if (x > n)
            break;
        if (x + qq - 1 <= n)
        {
            q += qq;
        }
        else
        {
            q += (n - x + 1);
        }
        x *= 2;
        qq *= 2;
    }
    return (q >= k);
}

long long bynk()
{
    long long l = 1, r = n;
    long long ans = 0;
    if (r % 2 == 0)
        --r;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (m % 2 == 0)
            --m;
        if (stg(m))
        {
            ans = m;
            l = m + 2;
        }
        else
        {
            r = m - 2;
        }
    }
    return ans;
}

long long bynz()
{
    long long l = 2, r = n;
    long long ans = 0;
    if (r % 2 == 1)
        --r;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (m % 2 == 1)
            --m;
        if (stg(m))
        {
            ans = m;
            l = m + 2;
        }
        else
        {
            r = m - 2;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    long long ans = 0;
    ans = max(ans, bynk());
    ans = max(ans, bynz());
    cout << ans << endl;
    return 0;
}