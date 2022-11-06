/*
	
	
	
	
	
	

	
	
	
										Naicissu
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9'&&ch >= '0')sum=sum*10+ch-'0',ch=getchar();
	return sum * nega;
}
const int N = 2e5 + 9;
int n, m, dp[N][8];
char a[N], p[8]; 
signed main()
{
	n = read(), m = read();
	scanf("%s", a + 1);
	for (int i = 1; i <= 6; i++)
	{
		if (i == 1) p[0] = 'a', p[1] = 'b', p[2] = 'c';
		else if (i == 2) p[0] = 'a', p[1] = 'c', p[2] = 'b';
		else if (i == 3) p[0] = 'b', p[1] = 'a', p[2] = 'c';
		else if (i == 4) p[0] = 'b', p[1] = 'c', p[2] = 'a';
		else if (i == 5) p[0] = 'c', p[1] = 'a', p[2] = 'b';
		else p[0] = 'c', p[1] = 'b', p[2] = 'a';
		for (int j = 1; j <= n; j++) dp[j][i] = dp[j - 1][i] + (a[j] != p[j % 3]);
	}
	for (int i = 1; i <= m; i++)
	{
		int l = read(), r = read();
		int ans = 1e18;
		for (int j = 1; j <= 6; j++) ans = min(ans, dp[r][j] - dp[l - 1][j]);
		printf("%lld\n", ans); 
	}
	return 0;
}