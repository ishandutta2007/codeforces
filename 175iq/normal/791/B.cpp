#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

void dfs(int i,int& edges, int& vertices, std::vector<int> adjlist[],std::vector<bool>& visited)
{
	visited[i]=1;
	vertices++;
	edges+=adjlist[i].size();
	for (int j : adjlist[i])
	{
		if(!visited[j])
		{
			dfs(j,edges,vertices,adjlist,visited);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	std::vector<int> adjlist[n+1];
	std::vector<bool> visited(n+1,0);

	int a,b;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	int edges,vertices;
	for (int i = 1; i <= n; ++i)
	{	
		edges=0;
		vertices=0;
		if(!visited[i])
		{
			dfs(i,edges,vertices,adjlist,visited);
			if(edges!=((longl)vertices)*(vertices-1))
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}