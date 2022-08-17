#include <iostream>
#include <vector>
 
#define MAXN 200005
#define LOG 20
 
std::vector<std::vector<int> > Adj(MAXN);
int par[LOG][MAXN];
int lev[MAXN];
 
int n, q;
 
void dfs(int u, int p = -1)
{
  lev[u] = 0;
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
  int v = lca(a, b);
  return lev[a] + lev[b] - 2*lev[v];
}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> n >> q;
	
	
	for(int i = 0; i < LOG; i++)
	{
		for(int j = 0; j < n; j++)
		{
			par[i][j] = -1;
		}
	}
	
	for(int i = 1; i < n; i++)
	{
    int y;
		std::cin >> y;
    y--;
		Adj[i].push_back(y);
		Adj[y].push_back(i);
	}
	
	dfs(0);
	
	for(int i = 0; i < q; i++)
	{
    int a, b, c;
		std::cin >> a >> b >> c;
		a--; b--; c--;
    int x = dis(a, b); int y = dis(b, c); int z = dis(c, a);
    int sum = (x+y+z)/2;
    std::cout << sum + 1 - std::min(x, std::min(y, z)) << std::endl;
	}
	
	return 0;
}