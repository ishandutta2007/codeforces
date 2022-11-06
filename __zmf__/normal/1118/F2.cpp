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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 3e5 + 9, mod = 998244353;
int n, k, dep[N], dp[N][2], fa[N][21];
int col[N], top[N];
vector<int> G[N], bel[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
inline void dfs1(int u, int f)
{
	fa[u][0] = f;
	for (int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	dep[u] = dep[f] + 1;
	for (auto v : G[u])
		if(v != f)
			dfs1(v, u);
}
inline int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	for (int i = 20; i >= 0; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	if(x != y) x = fa[x][0], y = fa[y][0];
	return x;
}
inline int work(int now, int fi, int c)
{
	if(now == fi) return 0;
	while(now != fi)
	{
		now = fa[now][0];
		if(col[now] != c && col[now] != 0) return -1;
		if(col[now] == c) return 0;
		col[now] = c;
	}
	return 0;
}
inline void paint(int p)
{
	int x = 0;
	for (auto i : bel[p])
	{
		if(!x) x = i;
		else x = LCA(x, i);
	}
//	cout << p << " " << x << endl;
	for (auto i : bel[p]) 
		if(work(i, x, p) == -1)
		{
			puts("0");
			exit(0);
		}
	top[p] = x;
	dp[x][1] = 1;
	return ;
}
inline void dfs2(int u, int f)
{
	int now = 1;
	for (auto v : G[u])
		if(v != f)
		{
			dfs2(v, u);
			if(col[u] && col[u] != col[v]) dp[top[col[u]]][1] = dp[top[col[u]]][1] * (dp[v][0] + dp[v][1]) % mod;
			now = now * (dp[v][0] + dp[v][1]) % mod;
		}
	if(col[u]) return ;
	dp[u][0] = now; dp[u][1] = 0;
	for (auto v : G[u])
		if(v != f) dp[u][1] = (dp[u][1] + now * dp[v][1] % mod * Pow(dp[v][0] + dp[v][1], mod - 2) % mod) % mod;
	return ;
}
signed main() 
{	
	n = read(), k = read();
	for (int i = 1; i <= n; i++) 
	{
		col[i] = read();
		if(col[i]) bel[col[i]].push_back(i);
	}
	for (int i = 1; i < n; i++) 
	{
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	dfs1(1, 0);
	for (int i = 1; i <= k; i++) paint(i);
	dfs2(1, 0);
	cout << dp[1][1] << endl;
	return 0;
}