#include <iostream>
#include <vector>
#include <set>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int N, M;
	std::cin >> N >> M;
	
	std::vector<std::pair<int, long long>> Adj[N];
	for(int i  = 0; i < M; i++)
	{
		int a, b; long long w;
		std::cin >> a >> b >> w;
		Adj[a-1].push_back({b-1, w});
		Adj[b-1].push_back({a-1, w});
	}
	
	long long d[N];
	std::set<std::pair<long long, int>> s;
	for(int i = 0; i < N; i++)
	{
		std::cin >> d[i];
		s.insert({d[i], i});
	}
	
	int u;
	while(!s.empty())
	{
		u = s.begin()->second;
		s.erase(s.begin());
		
		for(int i = 0; i < Adj[u].size(); i++)
		{
			std::pair<int, long long> e = Adj[u][i];
			if(d[e.first] > d[u] + 2*e.second)
			{
				s.erase({d[e.first], e.first});
				d[e.first] = d[u] + 2*e.second;
				s.insert({d[e.first], e.first});
			}
		}
	}
	
	for(int i = 0; i < N; i++)
		std::cout << d[i] << " ";
	
	return 0;
}