#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int> > adjlist(100010);
std::vector<int> side(100010,-1);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	int u,v;
	bool bipartite=1;

	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);		
	}

	queue<int> Q;
	int current;

	int count0=0;
	int count1=0;

	for (int i = 1; i <= n; ++i)
	{
		if(side[i]==-1)
		{
			Q.push(i);
			side[i]=0;
			count0++;
			while(!Q.empty())
			{
				current=Q.front();
				Q.pop();
				for (int j : adjlist[current])
				{
					if(side[j]==-1)
					{
						if(side[current]==1)
						{
							side[j]=0;
							count0++;
						}
						else
						{
							side[j]=1;
							count1++;
						}
						Q.push(j);
					}
					else
					{
						bipartite&=(side[current]!=side[j]);
					}
				}
			}
		}
	}

	if(!bipartite)
	{
		cout<<"-1";
	}
	else
	{
		cout<<count0<<endl;
		for (int i = 1; i <= n; ++i)
		{	
			if(!side[i])
			{
				cout<<i<<" ";
			}
		}
		cout<<endl;
		cout<<count1<<endl;
		for (int i = 1; i <= n; ++i)
		{	
			if(side[i])
			{
				cout<<i<<" ";
			}
		}
	}
	return 0;
}