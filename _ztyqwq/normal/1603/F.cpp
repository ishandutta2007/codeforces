#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
#define int ll
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
int inv2 = inv(2);
int smul[10000010];
int invks[10000010];
inline void InitInv(int n)
{
	int pown = fastpow(2, n);
	smul[n + 1] = 1;
	for(int i = n; i >= 1; i--)
	{
		smul[i] = smul[i + 1] * (pown - 1) % mod;
		pown = pown * inv2 % mod;
	}
	int tot = smul[1], pmul = 1, p = 2;
	int itot = inv(tot);
	for(int i = 1; i <= n; i++)
	{
		invks[i] = smul[i + 1] * pmul % mod * itot % mod;
		pmul = pmul * (p - 1) % mod;
		p = p * 2 % mod;
	}
}
signed main()
{
	InitInv(10000000);
	int T;
	scanf("%lld", &T);
	while(T--)
	{
		int n, k, x;
		scanf("%lld %lld %lld", &n, &k, &x);
		int powm = fastpow(2, k);
		if(x)
		{
			int pown = fastpow(2, n), powi = 1, Gauss = 1, mul = 1, lim = min(n, k);
			int ans = 0, tot = fastpow(powm, n);
			for(int i = 0; i <= lim; i++)
			{
				ans = (ans + Gauss * mul % mod * (powi - 1)) % mod;
				if(i == lim)
					break;
				Gauss = Gauss * (pown - 1) % mod * invks[i + 1] % mod;
				pown = pown * inv2 % mod;
				mul = mul * (powm - powi + mod) % mod;
				powi = powi * 2 % mod;
			}
			ans = ans * inv(powm - 1) % mod;
			printf("%lld\n", (tot - ans + mod) % mod);
		}
		else
		{
			int pown = fastpow(2, n), powi = 1, Gauss = 1, mul = 1, lim = min(n, k);
			int ans = 0;
			if(lim == n)
			{
				for(int i = 0; i <= lim; i++)
				{
					if(i == lim)
					{
						ans = Gauss * mul % mod;
						break;
					}
					Gauss = Gauss * (pown - 1) % mod * invks[i + 1] % mod;
					pown = pown * inv2 % mod;
					mul = mul * (powm - powi + mod) % mod;
					powi = powi * 2 % mod;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}