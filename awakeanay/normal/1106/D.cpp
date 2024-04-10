#include <iostream>
#include <vector>
#include <set>

int main()
{
	int N, M;
	std::cin >> N >> M;
	
	std::vector<int> Adj[N];
	for(int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b; a--; b--;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	
	bool mark[N];
	for(int i = 0; i < N; i++)
		mark[i] = false;
	
	std::set<int> next;
	next.insert(0);
	mark[0] = true;
	
	while(!next.empty())
	{
		int u = *next.begin();
		next.erase(next.begin());
		std::cout << u + 1 << " ";
		for(int i = 0; i < Adj[u].size(); i++)
		{
			int v = Adj[u][i];
			if(!mark[v])
			{
				mark[v] = true;
				next.insert(v);
			}
		}
	}
	
	return 0;
}