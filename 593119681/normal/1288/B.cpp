#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int Case, a, b;
LL res;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &a, &b);
		res = 0;
		for (LL m = 10; m <= b + 1; m *= 10)
			res += a;
		printf("%lld\n", res);
	}
	return 0;
}