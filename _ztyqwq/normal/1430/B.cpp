#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[200001];
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n, k;
		scanf("%lld %lld", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= k; i++)
			a[n] += a[n - i];
		printf("%lld\n", a[n]);
	}
	return 0;
}