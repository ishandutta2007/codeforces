#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const long long M = 1000003;

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

void solv()
{
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long u = 1;
    for (long long i = 0; i < n; ++i)
    {
        u *= 2;
        if (u >= k)
            break;
    }
    if (k > u)
    {
        printf("1 1\n");
        return;
    }
    long long y = 0;
    u = 1;
    while (u <= (k - 1))
    {
        u *= 2;
        y += ((k - 1) / u);
    }
    long long h1, h2;
    h2 = (ast(ast(2, n), k - 1) * ast(ast(2, y), M - 2)) % M;
    if ((k - 1) >= M)
        h1 = 0;
    else
    {
        h1 = 1;
        u = (ast(2, n) - 1 + M) % M;
        for (long long i = 0; i < (k - 1); ++i)
        {
            h1 = (h1 * u) % M;
            u = (u - 1 + M) % M;
        }
        h1 = (h1 * ast(ast(2, y), M - 2)) % M;
    }
    printf("%lld %lld\n", (h2 - h1 + M) % M, h2);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}