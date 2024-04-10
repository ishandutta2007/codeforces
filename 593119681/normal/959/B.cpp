#include <map>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, m, k, Cost[N], Num[N], Min[N];
char st[23];
map <string, int> Map;
LL ans;

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", st);
		string s = st;
		Map[s] = i;
	}
	for (int i = 1; i <= n; i ++)
		scanf("%d", Cost + i);
	for (int i = 1, c; i <= k; i ++)
	{
		scanf("%d", &c);
		for (int j = 1, x; j <= c; j ++)
		{
			scanf("%d", &x);
			Num[x] = i;
			Min[i] = j == 1 ? Cost[x] : min(Cost[x], Min[i]);
		}
	}
	for (int i = 1; i <= m; i ++)
	{
		scanf("%s", st);
		string s = st;
		int g = Num[Map[s]];
		ans += Min[g];
	}
	printf("%lld\n", ans);
	return 0;
}