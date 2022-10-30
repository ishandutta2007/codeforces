#include <cstdio>
#include <iostream>

const int MAXN = 200050;
typedef long long ll;

ll a[MAXN];

ll dp[2][MAXN];
int used[2][MAXN];
int vv = 1;
ll n;

int rec(ll v, int type)
{    
	if (v == 1)
		return -1;
	if (used[type][v] == vv)
		return -1;
	else if (used[type][v])
	{
		return dp[type][v] == -1 ? -1 : 1;
	}
	

	used[type][v] = vv;;

	if (!type)
	{
		if (v + a[v] > n)
		{
			dp[type][v] = a[v];

			return 1;
		}
		if (rec(v+a[v], 1 - type) == -1)
		{
			dp[type][v] = -1;
			return -1;
		}
		dp[type][v] =  dp[1-type][v+a[v]] + a[v];
	}
	else
	{
		if (v - a[v] <= 0)
		{
			dp[type][v] = a[v];

			return 1;
		}

		if (rec(v-a[v], 1-type) == -1)
		{
			dp[type][v] = -1;
			return -1 ;
		}

		dp[type][v] = dp[1-type][v-a[v]] + a[v];
	}

	return 1;
}

int main()
{
#if 0
	freopen("a.in", "r", stdin);
#endif
	std::cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		scanf("%d", &a[i+2]);
	}

	for (int i = 2; i <= n; i++)
	{
		if (!used[0][i])
		{
			rec(i, 0);
		}
		vv++;
		if (!used[1][i])
		{
			rec(i, 1);
		}
		vv++;
	}


	for (int i = 1; i <= n-1; i++)
	{
		if (dp[1][i+1] == -1)
			printf("-1\n");
		else
			printf("%I64d\n", dp[1][i+1] + i);
		//std::cout << dp[1][i+1] + i << std::endl;
		//printf("%I64d\n", dp[1][i] + i);
	}
}