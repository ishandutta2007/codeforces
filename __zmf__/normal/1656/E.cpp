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
const int N = 2e5 + 9;
int T;
int n, deg[N], dep[N];
vector<int> G[N];
inline void dfs(int u, int f)
{
	for (auto v : G[u])
		if(v != f) 
		{
			dep[v] = dep[u] + 1; 
			dfs(v, u);
		}
}
inline void solve()
{
	n = read(); 
	for (int i = 1; i <= n; i++) 
	{
		deg[i] = 0; G[i].clear(); dep[i] = 0;
	}
	for (int i = 1; i < n; i++) 
	{
		int x = read(), y = read();
		G[x].push_back(y); G[y].push_back(x);
		deg[x]++, deg[y]++;
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		if(dep[i] & 1) printf("-%lld ", deg[i]);
		else printf("%lld ", deg[i]);
	puts(""); return ;
}
signed main()
{
	
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}