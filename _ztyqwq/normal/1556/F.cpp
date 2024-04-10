#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[15];
const int mod = 1000000007;
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
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
inline int frac(int a, int b)
{
	return a * inv((a + b) % mod) % mod;
}
int f[20000];
int pr[15][15];
inline int popcnt(int x)
{
	int res = 0;
	while(x)
	{
		res += (x & 1);
		x >>= 1;
	}
	return res;
}
signed main()
{
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			pr[i][j] = frac(a[i], a[j]);
	int mx = (1 << n);
	for(int i = 0; i < mx; i++)
	{
		if(popcnt(i) == 1)
		{
			f[i] = 1;
			continue;
		}
		for(int j = 1; j < mx; j++)
		{
			if((i & j) != j || i == j)
				continue;
			int oth = i - j, pro = 1;
			for(int k = 1; k <= n; k++)
				if((j >> (k - 1)) & 1)
				{
					for(int l = 1; l <= n; l++)
						if((oth >> (l - 1)) & 1)
							pro = pro * pr[k][l] % mod;
				}
			f[i] = (f[i] + f[j] * pro) % mod;
		}
		f[i] = (1 - f[i] + mod) % mod;
	}
	int ans = 0;
	for(int i = 0; i < mx; i++)
	{
		int oth = mx - 1 - i, pro = 1;
		for(int j = 1; j <= n; j++)
			if((i >> (j - 1)) & 1)
			{
				for(int l = 1; l <= n; l++)
					if((oth >> (l - 1)) & 1)
						pro = pro * pr[j][l] % mod;
			}
		ans = (ans + f[i] * pro % mod * popcnt(i)) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}