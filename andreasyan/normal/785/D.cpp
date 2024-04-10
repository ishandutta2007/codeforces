#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
const int M = 1000000007;

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

int f[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
}

int n;
char a[N];

int p[N], s[N];

int c(int n, int k)
{
    return (f[n] * 1LL * ast((f[k] * 1LL * f[n - k]) % M, M - 2)) % M;
}

int main()
{
    pre();
    scanf(" %s", a);
    n = strlen(a);
    if (a[0] == '(')
        p[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] == '(')
            ++p[i];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        s[i] = s[i + 1];
        if (a[i] == ')')
            ++s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
        {
            ans = (ans + c(p[i] + s[i + 1], p[i])) % M;
            ans = (ans - c(p[i] + s[i + 1] - 1, p[i] - 1) + M) % M;
        }
    }
    printf("%d\n", ans);
    return 0;
}