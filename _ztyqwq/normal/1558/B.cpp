#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int f[4000001], s[4000001], d[4000001];
signed main()
{
	int n, mod;
	scanf("%lld %lld", &n, &mod);
	d[1] = 1;
	d[2] = mod - 1;
	int sumd = 0;
	for(int i = 1; i <= n; i++)
	{
		sumd = (sumd + d[i]) % mod;
		f[i] = (s[i - 1] + sumd) % mod;
		for(int j = 2; i * j <= n; j++)
		{
			d[i * j] = (d[i * j] + f[i]) % mod;
			if((i + 1) * j <= n)
				d[(i + 1) * j] = (d[(i + 1) * j] - f[i] + mod) % mod;
		}
		s[i] = (s[i - 1] + f[i]) % mod;
	}
	printf("%lld\n", f[n]);
	return 0;
}