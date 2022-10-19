#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 22, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int f[N], rf[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int C(long long n, int k)
{
    int ans = 1;
    for (long long i = n; i >= n - k + 1; --i)
    {
        ans = (ans * 1LL * (i % M)) % M;
    }
    ans = (ans * 1LL * rf[k]) % M;
    return ans;
}

int n;
long long s;
long long a[N];

void solv()
{
    scanf("%d%lld", &n, &s);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    int ans = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        int yans = 0;
        long long ss = s;
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                ss -= (a[i] + 1);
                ++q;
            }
        }
        if (ss >= 0)
        {
            yans = C(ss + n - 1, n - 1);
        }
        if (q % 2 == 0)
            ans = (ans + yans) % M;
        else
            ans = (ans - yans + M) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}