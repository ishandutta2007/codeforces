/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int N = 3e5 + 9, T = 550;
int n, B, soncnt[N], siz[N], dfn[N], tim, dep[N];
int tmp[N], cnt, fi[N];
char dp[N][T];
long long ans;
vector<int> G1[N], G[N];
struct point
{
	int v, pos;
}p[N];
inline void dfs1(int u, int f) 
{
	dfn[u] = ++tim;
	for (auto v : G1[u]) 
		if(v != f) 
		{
			dfs1(v, u);
			dep[u] = max(dep[u], dep[v]);
			soncnt[dfn[u]]++; 
			G[dfn[u]].push_back(dfn[v]);
		}
	//cout << u << " " << dep[u] << endl;
	ans += dep[u];
	dep[u]++; 
	return ;
}
inline void dfs(int u, int f)
{
	for (auto v : G[u]) 
	{
		dfs(v, u);
		for (int j = 2; j <= B; j++) dp[u][j] = max(dp[u][j], dp[v][j]);
		fi[u] = max(fi[u], fi[v]);
	}
	for (int j = 2; j <= B + 1; j++) ans += (int)dp[u][j];
	ans += fi[u];
//	for (int j = 2; j <= B + 1; j++) cout << dp[u][j] << " "; cout << endl;
}
inline bool cmp1(point x, point y)
{
	return x.v > y.v;
}
inline bool cmp2(point x, point y)
{
	return x.pos > y.pos;
}
inline bool cmp3(int x, int y) 
{
	return x > y;
}
signed main()
{
	n = read(); B = sqrt(n);
	if(B + 1 <= n) B++;
	for (int i = 1; i < n; i++) 
	{
		int x = read(), y = read();
	//	int x = 1, y = i + 1;
		G1[x].push_back(y); G1[y].push_back(x);
	}
	ans += 1ll * n * n;
	dfs1(1, 0);
	for (int i = 1; i <= n; i++) p[i].pos = i, p[i].v = soncnt[i];
	sort(p + 1, p + n + 1, cmp1);
//	cout << ans << endl;
	for (int i = B; i >= 2; i--) 
	{
		int now = n + 1;
		for (int j = 1; j <= n; j++)
			if(p[j].v < i) 
			{
				now = j; break;
			}
		now--;
		sort(p + 1, p + now + 1, cmp2);
	
		for (int j = 1; j <= now; j++) 
		{
			cnt = 0;
			for (auto v : G[p[j].pos]) 
				if(dp[v][i]) tmp[++cnt] = dp[v][i];
			if(cnt < i) dp[p[j].pos][i] = 1; 
			else
			{
				sort(tmp + 1, tmp + cnt + 1, cmp3); 
				dp[p[j].pos][i] = tmp[i] + 1; 	
				//cout << i << " " << ans << endl;
			}
		}
		sort(p + 1, p + now + 1, cmp1);
	//	dfs(1, 0);
	//	cout << i << " " << ans << endl;
	}
	//cout << B << endl;
	for (int i = 1; i <= n; i++) fi[i] = max(0, soncnt[i] - B);
	//cout << dp[1][B + 1] << endl;
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}