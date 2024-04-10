#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int> > adjlist(105);
std::vector<int> visited(105,0);

void dfs(int x)
{
	if(visited[x])
	{
		return;
	}

	visited[x]=true;

	for (int i = 0; i < adjlist[x].size(); ++i)
	{
		if(!visited[ adjlist[x][i] ])
		{
			dfs(adjlist[x][i]);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	int x,y;

	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
	}

	int ans=0;
	for (int i = 1; i <= n; ++i)
	{
		if(!visited[i])
		{
			dfs(i);
			ans++;
		}
	}

	if(ans==1 && (n==m))
	{
		cout<<"FHTAGN!";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}