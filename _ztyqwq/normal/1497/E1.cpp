#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int primes[1000001], pcnt = 0;
bool isp[10000001];
inline void Init(int n)
{
	isp[1] = true;
	for(int i = 2; i <= n; i++)
	{
		if(!isp[i])
			primes[++pcnt] = i;
		for(int j = 1; j <= pcnt && i * primes[j] <= n; j++)
		{
			isp[i * primes[j]] = true;
			if(i % primes[j] == 0)
				break;
		}
	}
}
inline int chan(int x)
{
	int s = sqrt(x);
	for(int i = 1; i <= pcnt; i++)
	{
		if(primes[i] > s)
			break;
		while(x % (primes[i] * primes[i]) == 0)
			x /= (primes[i] * primes[i]);
		if(x == 1)
			break;
	}
	return x;
}
int a[200001];
bool b[10000001];
signed main()
{
	int t;
	scanf("%lld", &t);
	Init(10000000);
	memset(b, false, sizeof(b));
	while(t--)
	{
		int n, k;
		scanf("%lld %lld", &n, &k);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			a[i] = chan(a[i]);
		}
		int ans = 0, p = 1;
		for(int i = 1; i <= n; i++)
		{
			if(b[a[i]])
			{
				for(int j = p; j < i; j++)
					b[a[j]] = false;
				ans++;
				p = i;
			}
			b[a[i]] = true;
		}
		for(int i = p; i <= n; i++)
			b[a[i]] = false;
		ans++;
		printf("%lld\n", ans);
	}
	return 0;
}