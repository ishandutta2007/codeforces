#include <iostream>
#include <queue>
#include <vector>

long long dfs(int u, int seq[], std::vector<int> Adj[], int p)
{
	if(p != -1 && Adj[u].size() == 1)
		return 0;
	
	long long answer = 0;
	std::priority_queue<long long> pq;
	
	if(p != -1)
	{
		answer++;
		seq[u]--;
	}
	
	for(int i = 0; i < Adj[u].size(); i++)
	{
		if(Adj[u][i] != p)
		{
			long long toAdd = dfs(Adj[u][i], seq, Adj, u);
			//std::cout << "\n" << Adj[u][i]+1 << " " << toAdd << "\n";
			pq.push(toAdd);
		}
	}
	
	while(!pq.empty() && seq[u] && pq.top())
	{
		long long a = pq.top(); pq.pop();
		answer += 1 + a;
		seq[u]--;
	}
	
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i]; if(v == p) continue;
		answer += 2*std::min(seq[u], seq[v]);
		seq[u] -= std::min(seq[u], seq[v]);
	}
	
	return answer;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	
	int seq[N];
	for(int i = 0; i < N; i++)
		std::cin >> seq[i];
	
	std::vector<int> Adj[N];
	for(int i = 0; i < N-1; i++)
	{
		int u, v;
		std::cin >> u >> v; u--; v--;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	
	int s;
	std::cin >> s; s--;
	
	std::cout << dfs(s, seq, Adj, -1);
	
	return 0;
}