#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a[100005];
long long sums[100005];
int n, t;

int main()
{
	scanf("%d %d\n", &n, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
//	reverse(a, a+n);

	sums[0] = 0;
	for (int i = 1; i < n+1; i++)
	{
		sums[i] = sums[i-1] + a[i-1];
	}

	int ans = 0;

	for (int i=0; i < n;i++)
	{
		long long *p = lower_bound(sums+i, sums+n, sums[i]+t);
		if(*p > sums[i]+t)
			p--;
		//int p = lower_bound(sums+i, sums+n, sums[i]+t)-(sums+i);
		ans = max(ans, p-sums-i);
	}

	printf("%d", ans);
}