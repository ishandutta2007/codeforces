#include <bits/stdc++.h>
using namespace std;

long long k;

const long long m = 14;
long long q[m];
long long p[m];
long long p1[m];

long long stgg(long long x)
{
    if (x == 0)
        return 0;
    long long xx = x / 10;
    long long tq = 1;
    long long s = 1;
    while (xx)
    {
        ++tq;
        xx /= 10;
        s *= 10;
    }
    return (p[tq - 1] + p1[tq - 1] * (x - s + 1) + ((x - s + 1) * (x - s + 2) / 2) * tq);
}

bool stg(long long x)
{
    return k <= stgg(x);
}

long long stgg1(long long x)
{
    if (x == 0)
        return 0;
    long long xx = x / 10;
    long long tq = 1;
    long long s = 1;
    while (xx)
    {
        ++tq;
        xx /= 10;
        s *= 10;
    }
    return (p1[tq - 1] + (x - s + 1) * tq);
}

bool stg1(long long x)
{
    return k <= stgg1(x);
}

long long tq(long long x)
{
    long long ans = 0;
    while (x)
    {
        ++ans;
        x /= 10;
    }
    return ans;
}

void solv()
{
    cin >> k;
    long long s = 9;
    for (long long i = 1; i < m; ++i)
    {
        q[i] = ((s * (s + 1)) / 2) * i + p1[i - 1] * s;
        p[i] = (p[i - 1] + q[i]);
        p1[i] = (p1[i - 1] + s * i);
        s *= 10;
    }
    for (long long i = 1; i < m; ++i)
    {
        if (k <= p[i])
        {
            long long l = 1, r = 9;
            for (long long j = 0; j < i - 1; ++j)
            {
                l *= 10;
                r *= 10;
                r += 9;
            }
            long long ans;
            while (l <= r)
            {
                long long m = l + (r - l) / 2;
                if (stg(m))
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            k -= stgg(ans - 1);
            l = 1, r = ans;
            while (l <= r)
            {
                long long m = l + (r - l) / 2;
                if (stg1(m))
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            k -= stgg1(ans - 1);
            vector<int> v;
            while (ans)
            {
                v.push_back(ans % 10);
                ans /= 10;
            }
            reverse(v.begin(), v.end());
            cout << v[k - 1] << endl;
            break;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    /*long long ans = 0;
    for (long long i = 1; i <= 99; ++i)
    {
        for (long long j = 1; j <= i; ++j)
        {
            ans += tq(j);
        }
    }
    cout << ans << endl;
    return 0;*/
    int qq;
    cin >> qq;
    while (qq--)
    {
        solv();
    }
    return 0;
}