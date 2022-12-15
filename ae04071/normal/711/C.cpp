#include <cstdio>
#include <cstring>
#include <algorithm>

const long long INF = 987654321000000;

int n, m, k;
int color[110];
long long costt[110][110];

long long cache[110][110][110];

long long DP(int ind, int remain, int prev)
{
	if (ind == n)
	{
		if (remain != 1)
			return INF;
		else
			return 0;
	}

	if (remain <= 0)
		return INF;
	
	long long& ret = cache[ind][remain][prev];
	if (ret != -1) return ret;

	ret = INF;
	if (color[ind] != 0)
	{
		if (prev == color[ind] - 1 || prev == 105)
		{
			ret = std::min(ret, DP(ind + 1, remain, color[ind] - 1));
		}
		else
		{
			ret = std::min(ret, DP(ind + 1, remain - 1, color[ind] - 1));
		}

		return ret;
	}

	for (int i = 0; i < m; i++)
	{
		long long cost = costt[ind][i];

		if (prev == i || prev == 105)
		{
			ret = std::min(ret, cost + DP(ind + 1, remain, i));
		}
		else
		{
			ret = std::min(ret, cost + DP(ind + 1, remain - 1, i));
		}
	}

	return ret;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &color[i]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%I64d", &costt[i][j]);
		}
	}

	memset(cache, -1, sizeof(cache));

	long long min_cost = DP(0, k, 105);
	if (min_cost >= INF)
		printf("-1\n");
	else
		printf("%I64d\n", min_cost);

	return 0;
}