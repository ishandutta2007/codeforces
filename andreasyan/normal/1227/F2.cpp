#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long M = 998244353;

struct ban
{
    long long x;
    ban()
    {
        x = 0;
    }
    ban(long long x)
    {
        this->x = (x % M);
    }
};
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban ast(ban x, long long n)
{
    ban ans(1);
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}
ban operator/(const ban& a, const ban& b)
{
    return a * ast(b, M - 2);
}

ban f[N];
void pre()
{
    f[0] = ban(1);
    for (int i = 1; i < N; ++i)
    {
        f[i] = f[i - 1] * ban(i);
    }
}

ban C(int n, int k)
{
    return f[n] / (f[k] * f[n - k]);
}

int n, k;
int a[N];

int q;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    pre();
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == a[(i % n) + 1])
            ++q;
    }
    ban ans;
    for (int z = 0; z < (n - q); ++z)
    {
        if (((n - q) - z) % 2 == 1)
            ans = ans + ast(ban(2), (n - q) - z) / ban(2) * ast(ban(k), q) * ast(ban(k - 2), z) * C(n - q, z);
        else
            ans = ans + (ast(ban(2), (n - q) - z) - C((n - q) - z, ((n - q) - z) / 2)) / ban(2) * ast(ban(k), q) * ast(ban(k - 2), z) * C(n - q, z);
    }
    printf("%lld\n", ans.x);
    return 0;
}