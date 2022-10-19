#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5003;
const long long M = 1000000007;

long long ast(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

long long rast2;

long long n, m;

long long ans;
void rec(long long l, long long r)
{
    if (n / l == n / r)
    {
        ans += ((((r - l + 1) % M) * ((n % l + n % r) % M)) % M * rast2) % M;
        ans %= M;
        return;
    }
    long long m = (l + r) / 2;
    rec(l, m);
    rec(m + 1, r);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld%lld", &n, &m);
    rast2 = ast(2, M - 2);
    rec(1, m);
    printf("%lld\n", ans);
    return 0;
    long long yans = 0;
    for (long long i = 1; i <= m; ++i)
    {
        yans += (n % i);
        //printf("%lld %lld\n", i, n % i);
    }
    printf("%lld\n", yans);
    return 0;
}