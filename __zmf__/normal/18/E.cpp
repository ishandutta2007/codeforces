/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 509;
int dp[N][28][28], n, m, px[N][28][28], py[N][28][28], a[N][N], cost[N][28][28];
char s[N][N];
inline int get_val(int p, int x, int y)
{
	int res = 0;
	for (int i = 1; i <= m; i++)
		if(i & 1) res += (a[p][i] != x);
		else res += (a[p][i] != y);
//	cout << res << endl;
	return res;
}
inline int dfs(int now, int posx, int posy)
{
	if(now != 1) dfs(now - 1, px[now][posx][posy], py[now][posx][posy]);
	for (int i = 1; i <= m; i++)
		if(i & 1) putchar(posx + 'a' - 1);
		else putchar(posy + 'a' - 1);
	puts("");
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = s[i][j] - 'a' + 1;
	if(m == 1)
	{
		int ans = 0;
		for (int i = 1; i < n; i++)
			if(a[i][1] == a[i + 1][1]) ++ans, ++i;
		cout << ans << endl;
		for (int i = 1; i < n; i++)
			if(a[i][1] == a[i + 1][1])
			{
				for (int j = 1; j <= 26; j++)
					if(j != a[i][1] && j != a[i + 2][1])
					{
						a[i + 1][1] = j;
						break;
					}
			}
		for (int i = 1; i <= n; i++)
		{
			putchar(a[i][1] + 'a' - 1);
			puts("");
		}
		return 0;
	} 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 26; j++)
			for (int k = 1; k <= 26; k++)
				cost[i][j][k] = get_val(i, j, k); 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 26; j++)
			for (int k = 1; k <= 26; k++)
			{
				if(j == k) continue;
				int Min = 1e9, posx, posy;
				for (int x = 1; x <= 26; x++)
					for (int y = 1; y <= 26; y++)
						if(x != y && x != j && y != k && dp[i - 1][x][y] < Min) posx = x, posy = y, Min = dp[i - 1][x][y];
				dp[i][j][k] = Min + cost[i][j][k];
				px[i][j][k] = posx;
				py[i][j][k] = posy;
				//cout << j << " " << k << " " << posx << " " << posy << endl;
			}		
	}
	int Min = 1e9, posx, posy;
	for (int i = 1; i <= 26; i++)
		for (int j = 1; j <= 26; j++)
			if(i != j && dp[n][i][j] < Min) Min = dp[n][i][j], posx = i, posy = j;
//	cout << posx << " " << posy << endl;
	cout << Min << endl;
	dfs(n, posx, posy);
	return 0;
}