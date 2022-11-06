#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5
#define GAP 100

int n, Cnt[2], Sum[N], V[N];
LL x, ans;

inline int Get(LL x)
{
	int res = 0;
	for (; x; x >>= 1)
		res += (x & 1);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lld", &x);
		V[i] = Get(x);
		Sum[i] = (Sum[i - 1] ^ V[i]) & 1;
		for (int j = 0, sum = 0, Max = 0; j < i && j < GAP; j ++)
		{
			sum += V[i - j], Max = max(Max, V[i - j]);
			if ((sum & 1) == 0 && sum >= 2 * Max)
				ans ++;
		}
		if (i > GAP)
			Cnt[Sum[i - GAP - 1]] ++;
		ans += Cnt[Sum[i]];
	}
	printf("%lld\n", ans);
	return 0;
}