#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
map <int, int> Map;
LL ans;

int main()
{
	for (int e = 0; e < 2; e ++)
	{
		scanf("%d", &n);
		for (int i = 1, x, y; i <= n; i ++)
		{
			scanf("%d%d", &x, &y);
			Map[x] = max(Map[x], y);
		}
	}
	for (auto it = Map.begin(); it != Map.end(); it ++)
		ans += it -> second;
	printf("%lld\n", ans);
	return 0;
}