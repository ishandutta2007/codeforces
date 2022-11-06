#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define Mod 1000000007

int n, k, res, Sum[N], Fac[N], Inv[N], Pow[N];
char s[N];

inline int power(int u, int v)
{
    int res = 1;
    for (; v; v >>= 1)
    {
        if (v & 1) res = (LL) res * u % Mod;
        u = (LL) u * u % Mod;
    }
    return res;
}

inline int Com(int u, int v)
{
    if (u < v) return 0;
    return (LL) Fac[u] * Inv[v] % Mod * Inv[u - v] % Mod;
}

int main()
{
    scanf("%d%d", &n, &k);
    if (k >= n)
    {
        puts("0");
        return 0;
    }
    scanf("%s", s + 1);
    Fac[0] = Inv[0] = Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        Sum[i] = Sum[i - 1] + s[i] - '0';
        Fac[i] = (LL) Fac[i - 1] * i % Mod;
        Pow[i] = (LL) Pow[i - 1] * 10 % Mod;
    }
    Inv[n] = power(Fac[n], Mod - 2);
    for (int i = n - 1; i; i --)
        Inv[i] = (LL) Inv[i + 1] * (i + 1) % Mod;
    for (int i = n - 1; i >= 0; i --)
    {
        int t = n - i - 1, _res;
        if (i > 0)
        {
            _res = (LL) Sum[i] * Com(n - t - 2, k - 1) % Mod * Pow[t] % Mod;
            res = (res + _res) % Mod;
        }
        _res = (LL) (s[i + 1] - '0') * Com(n - t - 1, k) % Mod * Pow[t] % Mod;
        res = (res + _res) % Mod;
    }
    printf("%d\n", res);
    
    return 0;
}