#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int Case, n, A[N];
LL ans, Sum[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		ans = 0x8080808080808080LL;
		for (int i = 1; i <= n; i ++)
			scanf("%d", A + i);
		sort(A + 1, A + n + 1);
		for (int i = 1; i <= n; i ++)
			Sum[i] = Sum[i - 1] + A[i];
		LL u = 1LL * (n - 2) * A[1] + Sum[n];
		LL v = 1LL * (n - 2) * A[n] + Sum[n];
		if (u > 0 || v < 0)
		{
			puts("INF");
			continue ;
		}
		for (int i = 1; i <= n; i ++)
		{
			LL tmp = (Sum[i - 1] - 1LL * (i - 1) * A[i]) * (A[n] - A[i])
				+ (Sum[n] - Sum[i] - 1LL * (n - i) * A[i]) * (A[1] - A[i])
				- 1LL * (A[1] - A[i]) * (A[n] - A[i])
				- 1LL * (n - 1) * A[i] * A[i];
			ans = max(ans, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}