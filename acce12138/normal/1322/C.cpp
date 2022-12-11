#include <bits/stdc++.h>

const int maxn = 500111;
int n, m, eu[maxn], ev[maxn], ord[maxn];

long long c[maxn];
unsigned long long piv[maxn], val[maxn];

void solve()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%lld", c+i);
	memset(val, 0, sizeof(val[0]) * (n+1));
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d", eu+i, ev+i);
		val[ev[i]] ^= piv[eu[i]];
	}
	for(int i=1; i<=n; i++) ord[i] = i;
	std::sort(ord+1, ord+n+1, [](int x, int y) { return val[x] < val[y];});
	long long ans = 0, sum = 0;
	for(int i=1; i<=n; i++)
	{
		sum += c[ord[i]];
		if(i == n || val[ord[i]] != val[ord[i+1]])
		{
			if(val[ord[i]]) ans = std::__gcd(ans, sum);
			sum = 0;
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	std::mt19937_64 rng(std::chrono::high_resolution_clock().now().time_since_epoch().count());
	for(int i=0; i<maxn; i++)
	{
		piv[i] = static_cast<unsigned long long>(rng());
		if(piv[i] == 0) piv[i]++;
	}
	int tc;
	scanf("%d", &tc);
	while(tc--) solve();
	return 0;
}