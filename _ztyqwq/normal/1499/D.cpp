#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int primes[2000001], num[20000001], pcnt = 0;
bool isp[20000001];
inline void Init(int n)
{
	isp[1] = true;
	num[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		if(!isp[i])
			primes[++pcnt] = i, num[i] = 1;
		for(int j = 1; j <= pcnt && i * primes[j] <= n; j++)
		{
			isp[i * primes[j]] = true;
			if(i % primes[j] == 0)
			{
				num[i * primes[j]] = num[i];
				break;
			}
			else
				num[i * primes[j]] = num[i] + 1;
		}
	}
}
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}
int c, d, x;
inline int calc(int dx)
{
	if((dx + d) % c)
		return 0;
	return fastpow(2, num[(dx + d) / c]);
}
signed main()
{
	Init(20000000);
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld %lld %lld", &c, &d, &x);
		int s = sqrt(x), ans = 0;
		for(int i = 1; i <= s; i++)
		{
			if(x % i == 0)
			{
				ans += calc(i);
				if(i * i != x)
					ans += calc(x / i);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}