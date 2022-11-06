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
const int N = 3009, M = 5e6 + 9, mod = 998244353;
int n, tot, cnt, ind, dp[N][N], siz[N], tmp[N], sz[N], vis[N], edg[N];
vector<int> G[N];
inline void addedge(int u, int v)
{
	G[u].push_back(v); G[v].push_back(u);
}
struct point
{
	int x, y, v;
}q[M];
inline bool cmp(point xxx, point yyy)
{
	return xxx.v < yyy.v;
}
int fa[N];
inline int find(int x) 
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
inline void dfs(int u, int f)
{
	siz[u] = 1; dp[u][0] = 1; 
	for (auto v : G[u]) 
		if(v != f)
		{
			dfs(v, u);
		//	cout << u << " " << v << endl;
			for (int j = 0; j <= siz[u] + siz[v]; j++) tmp[j] = 0;
			for (int j = 0; j <= siz[u]; j++)
				for (int k = 0; k <= siz[v]; k++) 
					tmp[j + k] = (tmp[j + k] + dp[u][j] * dp[v][k] % mod) % mod;
			for (int j = 0; j <= siz[u] + siz[v]; j++) dp[u][j] = tmp[j];
			siz[u] += siz[v];
		}
	dp[u][0] = 0; 
	if(u <= n || vis[u]) dp[u][1] = (dp[u][1] + 1) % mod; 
}
signed main()
{
	n = read();
	for (int i = 1; i <= n * 2 - 1; i++) fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int x = read();
			if(i < j) ++tot, q[tot].x = i, q[tot].y = j, q[tot].v = x;
		}
	sort(q + 1, q + tot + 1, cmp); ind = n;
	for (int i = 1; i <= tot; i++)
	{
		int fx = find(q[i].x), fy = find(q[i].y);
	//	cout << fx << " " << fy << endl;
		if(fx != fy) 
		{
			fa[fx] = fa[fy] = ++ind; 
			sz[ind] = sz[fx] + sz[fy]; 
			edg[ind] = edg[fx] + edg[fy] + 1;
			addedge(fx, ind); addedge(fy, ind); 
			if(sz[ind] * (sz[ind] - 1) / 2 == edg[ind]) 
			{
			//	cout << ind << endl;
				vis[ind] = 1;
			}
		//	cout << fx << " " << fy << " " << ind << endl; 
		}
		else 
		{
			edg[fx]++; 
			if(sz[fx] * (sz[fx] - 1) / 2 == edg[fx]) 
			{
			//	cout << fx << endl;
				vis[fx] = 1;
			}
		}
	}
	dfs(ind, ind);
	for (int i = 1; i <= n; i++) printf("%lld ", dp[ind][i]);
	return 0;
}