#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const long long N = 100005, INF = 1000000009000006;

long long qq = 0, uu = 0;

void solv(long long n, long long q, long long u)
{
    if (n == 0)
    {
        if (q > qq)
        {
            qq = q;
            uu = u;
        }
        else if (q == qq)
            uu = max(uu, u);
        return;
    }
    long long x = 1;
    while ((x + 1) * (x + 1) * (x + 1) <= n)
        ++x;
    solv(n - x * x * x, q + 1, u + x * x * x);
    if (x - 1 >= 1)
        solv(x * x * x - 1 - (x - 1) * (x - 1) * (x - 1), q + 1, u + (x - 1) * (x - 1) * (x - 1));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    long long n;
    scanf("%lld", &n);
    solv(n, 0, 0);
    printf("%lld %lld\n", qq, uu);
    return 0;
}