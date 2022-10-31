#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int d[100001];
struct Number
{
	int x, ind;
	bool operator < (const Number &ano) const
	{
		return x > ano.x;
	}
}a[100001];
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i].x), sum += a[i].x, a[i].ind = i;
		for(int i = 1; i <= n; i++)
			d[i] = 0;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%lld %lld", &u, &v);
			d[u]++, d[v]++;
		}
		sort(a + 1, a + n + 1);
		printf("%lld ", sum);
		int pos = 1;
		for(int i = 2; i < n; i++)
		{
			while(d[a[pos].ind] == 1)
				pos++;
			int u = a[pos].ind;
			d[u]--;
			sum += a[pos].x;
			printf("%lld ", sum);
		}
		putchar('\n');
	}
	return 0;
}