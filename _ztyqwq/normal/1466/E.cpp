#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[500001], cnt[61];
const int mod = 1000000007;
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			for(int j = 0; j < 60; j++)
				cnt[j] += ((a[i] >> j) & 1);
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ll tot1 = 0, tot2 = 0; 
			for(int j = 0; j < 60; j++)
				if((a[i] >> j) & 1)
					tot1 = (tot1 + (1ll << j) % mod * cnt[j]) % mod;
			for(int j = 0; j < 60; j++)
				if((a[i] >> j) & 1)
					tot2 = (tot2 + (1ll << j) % mod * n) % mod;
				else
					tot2 = (tot2 + (1ll << j) % mod * cnt[j]) % mod;
			ans = (ans + tot1 * tot2) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}