#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const long long M = 998244353;

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

long long n, m, l, r;

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%lld%lld%lld%lld", &n, &m, &l, &r);
    n *= m;
    if (n % 2 == 1)
    {
        printf("%lld\n", ast(r - l + 1, n));
    }
    else
    {
        if ((r - l + 1) % 2 == 0)
            printf("%lld\n", (ast(r - l + 1, n) * ast(2, M - 2)) % M);
        else
            printf("%lld\n", ((ast(r - l + 1, n) + 1) * ast(2, M - 2)) % M);
    }
    return 0;
}