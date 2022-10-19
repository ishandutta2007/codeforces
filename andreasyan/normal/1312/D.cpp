#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 998244353;

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

int n, m;

int f[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
}

int C(int n, int k)
{
    if (k > n)
        return 0;
    return (f[n] * 1LL * ast((f[n - k] * 1LL * f[k]) % M, M - 2)) % M;
}

int main()
{
    pre();
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int d = 1; d < m; ++d)
    {
        if (n > 2)
        {
            ans = (ans + (d * 1LL * C(d - 1, n - 3)) % M * 1LL * ast(2, n - 3)) % M;
        }
    }
    printf("%d\n", ans);
    return 0;
}