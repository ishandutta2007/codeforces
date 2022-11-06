#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int T;
LL S_1[N], S_2[N];

int Get_lev(LL x)
{
	if (x == 1) return 0;
	else return Get_lev(x >> 1) + 1;
}

int main()
{
	for (scanf("%d", &T); T; T --)
	{
		int op;
		LL x, k;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%lld%lld", &x, &k);
			int lev = Get_lev(x);
			S_1[lev] += k;
			LL tmp = 1LL << lev;
			S_1[lev] = (S_1[lev] % tmp + tmp) % tmp;
		}
		else if (op == 2)
		{
			scanf("%lld%lld", &x, &k);
			int lev = Get_lev(x);
			S_2[lev] += k;
			LL tmp = 1LL << lev;
			S_2[lev] = (S_2[lev] % tmp + tmp) % tmp;
		}
		else if (op == 3)
		{
			scanf("%lld", &x);
			int lev = Get_lev(x);
			for (LL fa; x; x = fa, lev --)
			{
				printf("%lld ", x);
				LL st = 1LL << lev, del = x - st;
				del = (del + S_1[lev] + S_2[lev] - S_1[lev - 1] * 2 + st) % st;
				fa = (st + del) >> 1;
			}
			puts("");
		}
	}
	return 0;
}