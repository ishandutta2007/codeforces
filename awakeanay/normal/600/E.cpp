#include <iostream>
#include <vector>

#define MAXN 100001

int N;
int count[MAXN];
int best[MAXN];
bool big[MAXN];
long long answer[MAXN];
int col[MAXN];
std::vector<int> Adj[MAXN];
int size[MAXN];

void preCalc(int u, int p)
{
	int curSize = 1;
	for(int i = 0; i < Adj[u].size(); i++)
	{
		if(Adj[u][i] != p)
		{
			preCalc(Adj[u][i], u);
			curSize += size[Adj[u][i]];
		}
	}
	size[u] = curSize;
}

void add(int u, int p, int sign, int head)
{
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int next = Adj[u][i];
		if(next != p && !big[next])
			add(next, u, sign, head);
	}
	
	count[col[u]] += sign;
	
	if(sign < 0)
		return;
	
	if(count[col[u]] == best[head])
		answer[head] += col[u];
	if(count[col[u]] > best[head])
		best[head] = count[col[u]], answer[head] = col[u];
	
}

void dfs(int u, int p, bool keep)
{
	int max = -1; int bigChild = -1;
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int next = Adj[u][i];
		if(next != p && size[next] > max)
			max = size[next], bigChild = next;
	}
	
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int next = Adj[u][i];
		if(next != p && next != bigChild)
			dfs(next, u, false);
	}
	
	if(bigChild != -1)
	{
		dfs(bigChild, u, true);
		big[bigChild] = true;
		answer[u] = answer[bigChild];
		best[u] = best[bigChild];
	}
	
	add(u, p, 1, u);
	
	if(bigChild != -1)
		big[bigChild] = false;
		
	if(!keep)
		add(u, p, -1, u);
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	std::cin >> N;
	for(int i = 0; i < N; i++)
		std::cin >> col[i];
	
	for(int i = 0; i < N-1; i++)
	{
		int a, b;
		std::cin >> a >> b; a--; b--;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	
	preCalc(0, -1);
	dfs(0, -1, false);
	
	for(int i = 0; i < N; i++)
		std::cout << answer[i] << " ";
	
	return 0;
}