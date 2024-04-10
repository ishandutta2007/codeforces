#include <iostream>
#include <vector>

#define CHARS 26

bool dfs(int u, std::vector<int> Adj[], int val[], std::vector<int> dp[], int color[], int* answer)
{
	color[u] = 1;
	for(int i = 0; i < Adj[u].size(); i++)
	{
		if(color[Adj[u][i]] == 1)
			return false;
		if(color[Adj[u][i]] != 2)
			if(!dfs(Adj[u][i], Adj, val, dp, color, answer))
				return false;
		for(int j = 0; j < CHARS; j++)
			dp[u][j] = std::max(dp[u][j], dp[Adj[u][i]][j]);
	}
	dp[u][val[u]]++;
	*answer = std::max(*answer, dp[u][val[u]]);
	color[u] = 2;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int N, M;
	std::cin >> N >> M;
	
	int val[N];
	for(int i = 0; i < N; i++)
	{
		char input;
		std::cin >> input;
		val[i] = (int)(input - 'a');
	}
	
	std::vector<int> Adj[N];
	for(int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;
		Adj[a-1].push_back(b-1);
	}
	
	std::vector<int> dp[N];
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < CHARS; j++)
			dp[i].push_back(0);
			
	int color[N];
	for(int i = 0; i < N; i++)
		color[i] = 0;
	
	int answer = 0;
	for(int i = 0; i < N; i++)
	{
		if(color[i] == 0)
			if(!dfs(i, Adj, val, dp, color, &answer))
			{
				std::cout << -1;
				return 0;
			}
	}
	
	std::cout << answer;
	
	return 0;
}