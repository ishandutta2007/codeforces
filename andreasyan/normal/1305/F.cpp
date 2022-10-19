#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n;
long long a[N];

long long qry(long long x)
{
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < x)
            ans += (x - a[i]);
        else
            ans += min((a[i] % x), x - (a[i] % x));
        if (ans > n)
            return ans;
    }
    return ans;
}

long long qryy(long long x)
{
    long long ans = n;
    for (long long i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            ans = min(ans, qry(i));
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        ans = min(ans, qry(x));
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    long long ans = qry(2);
    for (int ii = 0; ii < 20; ++ii)
    {
        int i = rnd() % n + 1;
        ans = min(ans, qryy(a[i]));
        ans = min(ans, qryy(a[i] - 1));
        ans = min(ans, qryy(a[i] + 1));
    }
    printf("%lld\n", ans);
    return 0;
}