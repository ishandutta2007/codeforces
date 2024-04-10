#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n;
long long a[N];

bool stg(long long x)
{
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % x == 0)
            ++q;
        if ((q + n - i) * 2 < n)
            return false;
        if (q * 2 >= n)
            return true;
    }
    if (q * 2 >= n)
        return true;
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    long long ans = 1;
    for (int ii = 0; ii < 12; ++ii)
    {
        int k = rnd() % n + 1;
        long long x = a[k];
        vector<long long> v;
        for (long long i = 1; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                v.push_back(i);
                if (i != x / i)
                    v.push_back(x / i);
            }
        }
        sort(v.begin(), v.end());
        map<long long, int> mp;
        for (int i = 0; i < v.size(); ++i)
        {
            mp[v[i]] = i;
        }
        vector<int> g;
        g.assign(v.size(), 0);
        for (int i = 1; i <= n; ++i)
        {
            g[mp[gcd(a[i], x)]]++;
        }
        for (int i = v.size() - 1; i >= 0; --i)
        {
            int gg = 0;
            for (int j = i; j < v.size(); ++j)
            {
                if (v[j] % v[i] == 0)
                    gg += g[j];
            }
            if (gg * 2 >= n)
            {
                ans = max(ans, v[i]);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}