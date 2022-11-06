#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int Case;
LL n;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%lld", &n);
		LL m2 = 1, ret = n;
		while (ret % 2 == 0)
			ret /= 2, m2 *= 2;
		LL ans = min(m2 * 2, ret);
		if (ret > 1 && ans * (ans + 1) / 2 <= n)
			printf("%lld\n", ans);
		else puts("-1");
	}
	return 0;
}