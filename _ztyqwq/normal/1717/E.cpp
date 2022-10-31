#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
#define int ll
inline int lcm(int x, int y)
{
	return x / __gcd(x, y) * y % mod;
}
int primes[100010], phi[100010], pcnt = 0;
bool isp[100010];
inline void Init(int n)
{
	phi[1] = 0;
	isp[1] = true;
	for(int i = 2; i <= n; i++)
	{
		if(!isp[i])
			primes[++pcnt] = i, phi[i] = i - 1;
		for(int j = 1; j <= pcnt && i * primes[j] <= n; j++)
		{
			isp[i * primes[j]] = true;
			if(i % primes[j] == 0)
			{
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			}
			else
				phi[i * primes[j]] = phi[i] * (primes[j] - 1);
		}
	}
}
signed main()
{
	int n;
	scanf("%lld", &n);
	Init(100000);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j += i) // a + b = j, gcd(a, j) = i, c = n - j
			ans = (ans + lcm(i, n - j) * phi[j / i]) % mod;
	printf("%lld\n", ans);
	return 0;
}