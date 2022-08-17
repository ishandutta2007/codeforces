#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	
	std::unordered_map<long long, std::vector<long long>> Adj;
	for(int i = 0; i < N; i++)
	{
		long long a, b;
		std::cin >> a >> b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	
	std::unordered_map<long long, bool> visited;
	long long root;
	for(std::unordered_map<long long, std::vector<long long>>::iterator i = Adj.begin(); i != Adj.end(); i++)
	{
		if((*i).second.size() == 1)
		{
			root = (*i).first;
			break;
		}
	}
	
	std::cout << root << " ";
	long long last = root;
	while(!visited[last])
	{
		visited[last] = true;
		for(int i = 0; i < Adj[last].size(); i++)
		{
			if(!visited[Adj[last][i]])
			{
				last = Adj[last][i];
				std::cout << last << " ";
				break;
			}
		}
	}
	
	return 0;
}