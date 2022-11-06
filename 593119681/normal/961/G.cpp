#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define Mod 1000000007
#define Inv2 500000004

int n, k, sum, tmp, ans, Fac[N], Inv[N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

inline int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1) res = 1LL * res * u % Mod;
		u = 1LL * u * u % Mod;
	}
	return res;
}

inline int C(int u, int v)
{
	if (u < v || u < 0 || v < 0) return 0;
	return 1LL * Fac[u] * Inv[v] % Mod * Inv[u - v] % Mod;
}

int S(int u, int v)
{
	int res = 0;
	for (int i = 0; i <= k; i ++)
		res = Inc(res, 1LL * (i & 1 ? Mod - 1 : 1) * C(k, i) % Mod * Power(k - i, u) % Mod);
	res = 1LL * res * Inv[k] % Mod;
	return res;
}

int main()
{
	scanf("%d%d", &n, &k);
	Fac[0] = Inv[0] = Inv[1] = 1;
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		sum = Inc(sum, x);
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
		if (i > 1)
			Inv[i] = Mod - 1LL * (Mod / i) * Inv[Mod % i] % Mod;
	}
	for (int i = 2; i <= n; i ++)
		Inv[i] = 1LL * Inv[i - 1] * Inv[i] % Mod;
	tmp = Inc(S(n, k), 1LL * (n - 1) * S(n - 1, k) % Mod);
	ans = 1LL * sum * tmp % Mod;
	printf("%d\n", ans);
	return 0;
}