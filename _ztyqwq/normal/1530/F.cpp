#include <bits/stdc++.h>
using namespace std;
const int mod = 31607;
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
int inv[32000];
inline void InitInv()
{
	inv[1] = 1;
	for(int i = 2; i < mod; i++)
		inv[i] = mod - (mod / i) * inv[mod % i] % mod;
}
int n, a[30][30];
int p[30];
inline int co(int x)
{
	return (x & 1) ? 1 : mod - 1;
}
int dfs(int u, bool A, bool B)
{
	if(u == n + 1)
	{
		int ans = 1;
		for(int i = 1; i <= n; i++)
			ans = ans * (mod + 1 - p[i]) % mod;
		return ans;
	}
	int ans = 0, tot = 1;
	for(int i = 1; i <= n; i++)
	{
		if((u == i && A) || (u == n + 1 - i && B))
			tot = tot * a[u][i] % mod;
		else
			p[i] = p[i] * a[u][i] % mod;
	}
	ans += tot * dfs(u + 1, A, B);
	for(int i = 1; i <= n; i++)
		if(!(u == i && A) && !(u == n + 1 - i && B))
			p[i] = p[i] * inv[a[u][i]] % mod;
	tot = 1;
	for(int i = 1; i <= n; i++)
		tot = tot * a[u][i] % mod;
	ans += (mod - tot) % mod * dfs(u + 1, A, B);
	return ans % mod;
}
int main()
{
	InitInv();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]), a[i][j] = a[i][j] * inv[10000] % mod;
	for(int i = 1; i <= n; i++)
		p[i] = 1;
	int ans = dfs(1, false, false) - dfs(1, false, true) - dfs(1, true, false) + dfs(1, true, true);
	ans = (ans % mod + mod) % mod;
	printf("%d\n", (mod + 1 - ans) % mod);
	return 0;
}