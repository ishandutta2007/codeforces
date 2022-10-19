#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006, M = 1000000007;

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

int C(int n, int k)
{
    return (((f[n] * 1LL * rf[k]) % M) * 1LL * rf[n - k]) % M;
}

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (n == 1)
    {
        printf("0\n");
        return;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == a[n])
            break;
        if (a[i] != a[i - 1])
        {
            int q = i - 1;
            int t = n - i;
            int u = 0;
            for (int j = i; ; ++j)
            {
                if (a[j] != a[i])
                    break;
                ++u;
            }
            int yans = (((C(t + q + 1, t + 1) * 1LL * a[i]) % M) * ((f[t] * 1LL * f[q]) % M)) % M;
            yans = (yans * 1LL * u) % M;
            ans = (ans + yans) % M;
        }
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