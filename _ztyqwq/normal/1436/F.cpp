#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int mod = 998244353;
bool isp[100001];
int primes[100001], pcnt = 0;
int mu[100001];
inline void Init(int n)
{
	isp[1] = true;
	mu[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!isp[i])
			primes[++pcnt] = i, mu[i] = -1;
		for(int j = 1; j <= pcnt && i * primes[j] <= n; j++)
		{
			isp[i * primes[j]] = true;
			if(i % primes[j] == 0)
			{
				mu[i * primes[j]] = 0;
				break;
			}
			else
				mu[i * primes[j]] = -mu[i];
		}
	}
}
inline int fastpow(int a, int n)
{
	if(n < 0)
		return 0;
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
int MAXN = 100000;
int b[100001], p1[100001], p2[100001];
inline int CALC2(int n)
{
	return n <= 1 ? 0 : (n - 1) % mod * fastpow(2, n - 2) % mod;
}
inline int CALCMUL(int n)
{
	return n <= 2 ? max(n - 1, 0ll) : n % mod * fastpow(2, n - 3) % mod;
}
signed main()
{
	Init(100000);
	int n;
	scanf("%lld", &n);
	memset(b, 0, sizeof(b));
	memset(p1, 0, sizeof(p1));
	memset(p2, 0, sizeof(p2));
	while(n--)
	{
		int x, num;
		scanf("%lld %lld", &x, &num);
		b[x] += num;
		p1[x] = (p1[x] + x * num) % mod;
		p2[x] = (p2[x] + x * x % mod * num) % mod;
	}
	int ans = 0;
	for(int i = 1; i <= MAXN; i++)
	{
		int m = 0, tot1 = 0, tot2 = 0;
		for(int j = i; j <= MAXN; j += i)
		{
			m += b[j];
			tot1 = (tot1 + p1[j]) % mod;
			tot2 = (tot2 + p2[j]) % mod;
		}
		int mul = (tot1 * tot1 - tot2 + mod) % mod;
		int res = (tot2 * CALC2(m) % mod + mul * CALCMUL(m) % mod) % mod;
		ans = (ans + res * mu[i] + mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}