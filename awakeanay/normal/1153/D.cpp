#include <iostream>
#include <vector>

#define MAXN 300001

int leaves[MAXN];
int type[MAXN];
std::vector<int> Adj[MAXN];

int dfs(int u)
{
	//std::cout << u << std::endl;
	
	if(Adj[u].size() == 0)
	{
		//std::cout << "what";
		leaves[u] = 1;
		//std::cout << leaves[u] << std::endl;
		return 1;
	}
	
	int best = MAXN;
	if(!type[u])
		best = 0;
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int ret = dfs(Adj[u][i]);
		leaves[u] += leaves[Adj[u][i]];
		if(type[u])
		{
			//std::cout << ret << std::endl;
			best = std::min(best, leaves[Adj[u][i]] - ret);
		}
		else
			best += ret - 1;
	}
	
	if(type[u])
		return leaves[u] - best;
	else
		return best + 1;
}

int main()
{
	int n;
	std::cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		std::cin >> type[i];
		leaves[i] = 0;
	}
	
	for(int i = 0; i < n-1; i++)
	{
		int x;
		std::cin >> x;
		Adj[x-1].push_back(i+1);
	}
	
	std::cout << dfs(0);
	
	
	return 0;
}