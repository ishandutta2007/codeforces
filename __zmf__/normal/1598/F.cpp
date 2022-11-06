/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 29, M = 4e5 + 9, K = (1 << 22) + 9;
int n;
char s[M];
int val[N], len[N], pMin[N];
int sum[N][M], tot[N][M], pep[N][M * 2];
int dp[K][4], w[K], ans;
signed main()
{	 
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		scanf("%s", s + 1);
		len[i] = strlen(s + 1);
		for (int j = 1; j <= len[i]; j++) 
			if(s[j] == '(') sum[i][j] = sum[i][j - 1] + 1;
			else sum[i][j] = sum[i][j - 1] - 1;
		val[i] = sum[i][len[i]];
		int Min = M;
		for (int j = 1; j <= len[i]; j++)
		{
			pep[i][M + sum[i][j]]++;
			if(M + sum[i][j] < Min)
			{
				Min = M + sum[i][j];
				tot[i][Min] = pep[i][Min + 1];
			}
		}
		pMin[i] = Min - M;
	}
	for (int Mask = 1; Mask < (1 << n); Mask++) dp[Mask][0] = dp[Mask][1] = -1e9;
	for (int Mask = 1; Mask < (1 << n); Mask++)
	{
		for (int i = 1; i <= n; i++)
			if((Mask & (1 << (i - 1))))
			{
				int lst = (Mask ^ (1 << (i - 1)));
				w[Mask] = w[lst] + val[i];
				if(w[lst] + pMin[i] < 0) dp[Mask][1] = max(dp[Mask][1], dp[lst][0] + tot[i][M - w[lst] - 1]);
				else dp[Mask][0] = max(dp[Mask][0], dp[lst][0] + pep[i][M - w[lst]]); 
				dp[Mask][1] = max(dp[Mask][1], dp[lst][1]);
			}
		ans = max(ans, dp[Mask][0]);
		ans = max(ans, dp[Mask][1]);
	}
	cout << ans << endl;
	return 0;
}
//qwq