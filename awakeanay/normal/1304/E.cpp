/*
Author: AwakeAnay
Date: 15/02/2020
Time: 19:05:37
*/

#include <iostream>
#include <vector>
 
#define int long long
 
#define MAXN 200005
#define LOG 20
 
std::vector<int> Adj[MAXN];
int par[LOG][MAXN];
int lev[MAXN];
 
int n, q;
 
void dfs(int u, int p = -1)
{
	if(p != -1)
	{
		lev[u] = lev[p]+1;
		par[0][u] = p;
	}
	
	//std::cout << u << " " << lev[u] << std::endl;
	
	for(int i = 1; i < LOG; i++)
	{
		if(par[i-1][u] == -1)
			break;
		
		par[i][u] = par[i-1][par[i-1][u]];
	}
	
	for(int j : Adj[u])
		if(j != p)
			dfs(j, u);
}
 
int lca(int u, int v)
{
	if(lev[u] < lev[v])
		u ^= v ^= u ^= v;
	
	for(int i = LOG-1; i >= 0; i--)
	{
		if(lev[u] - lev[v] >= (1<<i))
			u = par[i][u];
	}
	
	//std::cout << u << " " << v << " is this right? " << std::endl;
	
	if(u == v)
		return u;
		
	for(int i = LOG-1; i >= 0; i--)
	{
		if(par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		}
	}
	
	return par[0][u];
}
 
int dis(int a, int b) {
	int x = lca(a, b);
	return lev[a] + lev[b] - 2*lev[x];
}
 
signed main()
{
	std::cin >> n;
	
	for(int i = 0; i < LOG; i++)
	{
		for(int j = 0; j < n; j++)
		{
			par[i][j] = -1;
		}
	}
	
	for(int i = 1; i < n; i++)
	{
		int a, b;
		std::cin >> a >> b;
		a--; b--;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	
	dfs(0);
	
	std::cin >> q;
	
	for(int i = 0; i < q; i++)
	{
		int x, y, a, b, k;
		std::cin >> x >> y >> a >> b >> k;
		a--; b--; x--; y--;

    bool poss = false;
    int d1 = dis(a,b);
    if(d1 <= k && d1%2 == k%2)
      poss = true;

    int d2 = dis(a,x) + dis(y, b) + 1;
    if(d2 <= k && d2%2 == k%2)
      poss = true;
    
    int d3 = dis(a,y) + dis(x, b) + 1;
    if(d3 <= k && d3%2 == k%2)
      poss = true;

    if(poss)
      std::cout << "YES";
    else
      std::cout << "NO";
    std::cout << std::endl;
	}
	
	return 0;
}