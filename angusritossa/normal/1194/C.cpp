#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int n;
int occ[3][30];
char inp[3][300];
int done[300][300], memo[300][300], len[3], upto;
int dp(int a, int b)
{
	if (done[a][b] == upto) return memo[a][b];
	done[a][b] = upto;
	if (a == len[0]) return memo[a][b] = 1;
	if (b == len[1]) return memo[a][b] = 0;
	int ans = 0;
	if (inp[0][a] == inp[1][b]) ans = max(ans, dp(a+1, b+1));
	ans = max(ans, dp(a, b+1));
	return memo[a][b] = ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fill_n(occ[j], 30, 0);
			scanf(" %s", inp[j]);
			int len = strlen(inp[j]);
			for (int k = 0; k < len; k++)
			{
				occ[j][inp[j][k]-'a']++;
			}
		}
		int good = 0;
		for (int i = 0; i < 26; i++)
		{
			if (occ[0][i]+occ[2][i] >= occ[1][i]) good++;
		}
		upto++;
		len[0] = strlen(inp[0]), len[1] = strlen(inp[1]);
		good += !!dp(0, 0);
		if (good == 27) printf("YES\n");
		else printf("NO\n");
	}
}