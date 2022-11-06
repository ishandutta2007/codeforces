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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 3009;
int T;
int n, m;
int b[N], w[N], v[N], siz[N];
vector<int> G[N];
struct node
{
	int w, v;
}dp[N][N], tmp[N];
inline node Max(node xxx, node yyy)
{
	if(xxx.w > yyy.w || (xxx.w == yyy.w && xxx.v > yyy.v)) return xxx;
	else return yyy; 
}
inline void dfs(int u, int f)
{
	siz[u] = 1; dp[u][1] = node{0, v[u]};
	for (auto v : G[u])
		if(v != f)
		{
			dfs(v, u);
			for (int i = 1; i <= siz[u] + siz[v]; i++) tmp[i] = {-1, 0};
			for (int i = 1; i <= siz[u]; i++)
				for (int j = 1; j <= siz[v]; j++)
				{
					tmp[i + j] = Max(tmp[i + j], node{dp[u][i].w + dp[v][j].w + (dp[v][j].v > 0), dp[u][i].v});
					tmp[i + j - 1] = Max(tmp[i + j - 1], node{dp[u][i].w + dp[v][j].w, dp[u][i].v + dp[v][j].v});
				}
			for (int i = 1; i <= siz[u] + siz[v]; i++) dp[u][i] = tmp[i];
			siz[u] += siz[v];
		}
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(), m = read();
		for (int i = 1; i <= n; i++) b[i] = read();
		for (int i = 1; i <= n; i++) w[i] = read();
		for (int i = 1; i <= n; i++) v[i] = w[i] - b[i], G[i].clear();
		for (int i = 1; i < n; i++) 
		{
			int x = read(), y = read(); G[x].push_back(y); G[y].push_back(x);
		}
		dfs(1, -1);
		printf("%lld\n", dp[1][m].w + (dp[1][m].v > 0));
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++)
				dp[i][j] = node{0, 0};
	}
	return 0;
}