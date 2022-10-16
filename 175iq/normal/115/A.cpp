#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int> > adjlist(2005);
std::vector<int> visited(2005,0);
std::vector<int> level(2005,0);

void dfs(int x)
{
	if(visited[x])
	{
		return;
	}
	level[x]++;
	for (int i = 0; i < adjlist[x].size(); ++i)
	{
		if(!visited[adjlist[x][i]])
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

	int n;
	cin>>n;

	int p;
	for (int i=1; i <=n; ++i)
	{
		cin>>p;
		if(p!=-1)
		{
			adjlist[p].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if(!visited[i])
		{
			dfs(i);	
		}
	}

	int ans=*max_element(level.begin(),level.end());
	cout<<ans;
	return 0;
}