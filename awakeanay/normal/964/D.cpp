#include <iostream>
#include <vector>

bool isAfter(long u, std::vector<long> Adj[], std::vector<long> before[], std::vector<long> after[])
{
	for(long i = 0; i < Adj[u].size(); i++)
	{
		long c = Adj[u][i];
		if(isAfter(c, Adj, before, after))
			after[u].push_back(c);
		else
			before[u].push_back(c);
	}
	return (after[u].size() % 2 == 0);
}

void traverse(long u, std::vector<long> before[], std::vector<long> after[])
{
	for(long i = 0; i < before[u].size(); i++)
		traverse(before[u][i], before, after);
	std::cout << u+1 << std::endl;
	for(long i = 0; i < after[u].size(); i++)
		traverse(after[u][i], before, after);
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	long N; long root;
	std::cin >> N;
	std::vector<long> Adj[N];
	std::vector<long> before[N];
	std::vector<long> after[N];
	
	for(long i = 0; i < N; i++)
	{
		long a;
		std::cin >> a; a--;
		if(a >= 0)
			Adj[a].push_back(i);
		else
			root = i;
	}
	
	if(isAfter(root, Adj, before, after))
	{
		std::cout << "YES" << std::endl;
		traverse(root, before, after);
	}
	else
		std::cout << "NO" << std::endl;
	
	return 0;
}