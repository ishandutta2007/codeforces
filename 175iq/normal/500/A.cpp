
#include <bits/stdc++.h>
using namespace std;



void dfs(std::vector<std::vector<int> >& adjlist, std::vector<bool>& visited,int current)
{
	visited[current]=1;
	for (int i = 0; i<adjlist[current].size() ; ++i)
	{
		if(!visited[adjlist[current][i]])
		{
			dfs(adjlist,visited,adjlist[current][i]);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,t;
	cin>>n>>t;

	int temp;
	std::vector<std::vector<int> > adjlist(n+1);
	std::vector<bool> visited(n+1,0);

	for (int i = 1; i <= n-1; ++i)
	{
		cin>>temp;
		adjlist[i].push_back(i+temp);
	}

	dfs(adjlist,visited,1);

	if(visited[t])
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}