/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
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
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 4009, mod = 1e9 + 7;
int n, m, cnt, ans;
int dp[2][3 * N][2];
vector<int> G[N];
int siz[N], sz[N];
int fa[N];
inline int Mod(int x) 
{
	return x >= mod ? (x - mod) : x;
}
inline int find(int x)
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i++) 
	{
		int x = read(), y = read();
		if(x == y || x == 1 || y == 1) continue;
		int fx = find(x), fy = find(y); 
		if(fx != fy) 
		{
			fa[fx] = fy, sz[fy] += sz[fx];
		//	cout << fy << " " << siz[fx] << " " <siz[fy] << "qwq" << endl;
		}
	} 
	for (int i = 1; i <= n; i++)
		if(find(i) == i && i != 1) siz[++cnt] = sz[i] + 1;
//	for (int i = 1; i <= cnt; i++) cout << siz[i] << " "; cout << endl;
	dp[0][m][0] = 1; 
	for (int i = 1; i <= cnt; i++)
	{
		int now = (i & 1), lst = (now ^ 1);
		for (int j = 0; j <= 2 * m; j++) 
			for (int k = 0; k < 2; k++) 
			{
				dp[now][j][k] = Mod(dp[lst][j][k] + dp[lst][j + siz[i]][k]);
				if(j >= siz[i]) dp[now][j][k] = Mod(dp[now][j][k] + dp[lst][j - siz[i]][k]);
			}
		
		for (int j = 1; j <= 2 * m; j++) dp[lst][j][0] = Mod(dp[lst][j][0] + dp[lst][j - 1][0]);
		for (int j = 0; j <= 2 * m; j++) 
		{
			int l = max(0ll, j - (siz[i] - 2)), r = min(2 * m, j + (siz[i] - 2));
			if(l == 0) dp[now][j][1] = Mod(dp[lst][r][0] + Mod(2 * dp[now][j][1]));
			else dp[now][j][1] = Mod(dp[now][j][1] + Mod(2 * Mod(dp[lst][r][0] - dp[lst][l - 1][0] + mod)));
		}
		for (int j = 0; j <= 2 * m; j++) dp[lst][j][0] = dp[lst][j][1] = 0;
		
	} 
	ans = Mod(dp[(cnt & 1)][m][1]);// cout << ans << endl;
	memset(dp, 0, sizeof(dp)); dp[0][m][0] = 1;
	for (int i = 1; i <= cnt; i++)
	{
		int now = (i & 1), lst = (now ^ 1);
		for (int j = 0; j <= 2 * m; j++) 
			for (int k = 0; k < 2; k++) 
			{
				dp[now][j][k] = dp[lst][j + siz[i]][k];
				if(j >= siz[i]) dp[now][j][k] = Mod(dp[now][j][k] + dp[lst][j - siz[i]][k]);
			}
		for (int j = 0; j <= 2 * m; j++) 
		{
			dp[now][j][1] = Mod(dp[now][j][1] + Mod(2 * dp[lst][j + siz[i] - 1][0]));
			if(j - siz[i] + 1 >= 0) dp[now][j][1] = Mod(dp[now][j][1] + Mod(2 * dp[lst][j - siz[i] + 1][0]));
		}
		for (int j = 0; j <= 2 * m; j++) dp[lst][j][0] = dp[lst][j][1] = 0;
	}
	ans = Mod(ans + dp[(cnt & 1)][m][1]);  ans = Mod(ans + dp[(cnt & 1)][m][0]);
	cout << ans << endl;
	return 0;
}