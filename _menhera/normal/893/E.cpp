#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e6, MOD = 1e9+7;

long long fact[MAXN], ifact[MAXN];

long long ipow(long long a, long long b)
{
	if(b == 0) return 1;
	long long ans = ipow(a, b/2);
	assert(ans >= 0);
	ans = ans*ans%MOD;
	if(b&1) ans = ans*a%MOD;
	return ans;
}

long long inv(long long a){ return ipow(a, MOD-2); }

long long H(int n, int r)
{
	return (fact[n+r-1]*ifact[r]%MOD)*ifact[n-1]%MOD;
}

int main()
{
	fact[0] = ifact[0] = 1;
	for(int i=1; i<MAXN; ++i)
	{
		fact[i] = i*fact[i-1]%MOD;
		ifact[i] = inv(fact[i]);
	}
	int T; scanf("%d", &T);
	while(T--)
	{
		int x, y; scanf("%d%d", &x, &y);

		long long ans = ipow(2, y-1);
		for(int i=2; i*i<=x; ++i)
		{
			int cnt = 0;
			while(x%i == 0)
			{
				x /= i;
				++cnt;
			}
			if(cnt != 0) ans = ans * H(y, cnt)%MOD;
		}
		if(x != 1) ans = ans * H(y, 1)%MOD;
		printf("%lld\n", ans);
	}
}