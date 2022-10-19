#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;
long long M;
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

ban f[N];
void pre()
{
    f[0] = ban(1);
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * ban(i);
}

int n;

int main()
{
    scanf("%d%lld", &n, &M);
    pre();
    ban ans;
    for (int d = 1; d <= n; ++d)
    {
        ans = ans + ban(n - d + 1) * f[d] * ban(n - d + 1) * f[n - d];
    }
    printf("%lld\n", ans.x);
    return 0;
}