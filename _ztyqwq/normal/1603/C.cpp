#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int a[100010];
int p[100010], res[100010];
ll sum[100010];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int r;
		ll ans = 0;
		// tot[0] = 1;
		for(r = 1; r <= n; r++)
		{
			p[r] = a[r];
			res[r] = 0;
			int j;
			for(j = r - 1; j >= 1; j--)
			{
				// i => k: q = a[i] / k, r = a[i] % k, q * (k - r) + (q + 1) * r, q + 1 <= S
				int k = (a[j] % p[j + 1] == 0 ? a[j] / p[j + 1] : a[j] / p[j + 1] + 1);
				int mn = a[j] / k;
				res[j] = k - 1;
				if(p[j] == mn)
					break;
				p[j] = mn;
			}
			for(; j <= r; j++)
				sum[j] = (sum[j - 1] + (ll)res[j] * j) % mod;
			ans = (ans + sum[r]) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}