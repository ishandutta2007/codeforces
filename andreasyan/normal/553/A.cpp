#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            ans = (ans * 1LL * x) % M;
        }
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n;
int a[N];

int f[N * N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N * N; ++i)
    {
        f[i] = (f[i - 1] * 1LL * i) % M;
    }
}

int C(int n, int k)
{
    return (f[n] * 1LL * ast((f[k] * 1LL * f[n - k]) % M, M - 2)) % M;
}

int dp[N][N];
int p[N][N];

int main()
{
    pre();
    scanf("%d", &n);
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        q += a[i];
    }
    int ans = 1;
    for (int i = n; i >= 1; --i)
    {
        --q;
        --a[i];
        ans = (ans * 1LL * C(q, a[i])) % M;
        q -= a[i];
    }
    printf("%d\n", ans);
    return 0;
}