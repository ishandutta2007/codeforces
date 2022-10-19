#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
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
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
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

ban inv[N];
void pre()
{
    for (int i = 1; i < N; ++i)
        inv[i] = ast(ban(i), M - 2);
}

int n;
int k[N];
vector<int> a[N];

int q[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &k[i]);
        for (int j = 0; j < k[i]; ++j)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
            q[x]++;
        }
    }
    pre();
    ban ans;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k[i]; ++j)
        {
            int x = a[i][j];
            ans = ans + inv[n] * inv[k[i]] * ban(q[x]) * inv[n];
        }
    }
    printf("%lld\n", ans.x);
    return 0;
}