#include <bits/stdc++.h>
using namespace std;
const int N = 100005, K = 450;
const long long M = 1000000007;

struct ban
{
    int x;
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
    return ban(a.x * 1LL * b.x);
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
ban inv(const ban& x)
{
    return ast(x, M - 2);
}

ban f[N];
ban invf[N];
ban ast25[N];
void pre()
{
    f[0] = ban(1);
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * ban(i);
    for (int i = 0; i < N; ++i)
        invf[i] = inv(f[i]);
    ast25[0] = ban(1);
    for (int i = 1; i < N; ++i)
        ast25[i] = ast25[i - 1] * ban(25);
}

ban C(long long n, long long k)
{
    return f[n] * invf[k] * invf[n - k];
}

int k;
int u[K];
ban ans[K][N];

int n;
int kk;

void ubd()
{
    for (int i = 1; i <= k; ++i)
    {
        if (u[i] == n)
        {
            kk = i;
            return;
        }
    }
    ++k;
    u[k] = n;
    kk = k;
    ans[k][n] = ban(1);
    for (int i = n + 1; i < N; ++i)
        ans[k][i] = ans[k][i - 1] * ban(26) + C(i - 1, n - 1) * ast25[i - n];
}

int m;
char s[N];
int main()
{
    /*int sum = 0;
    for (int i = 1; ; ++i)
    {
        sum += i;
        if (sum > N)
        {
            printf("%d\n", i);
            return 0;
        }
    }*/
    pre();
    scanf("%d", &m);
    scanf(" %s", s);
    n = strlen(s);
    ubd();
    while (m--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            scanf(" %s", s);
            n = strlen(s);
            ubd();
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", ans[kk][x].x);
        }
    }
    return 0;
}