#include <bits/stdc++.h>
using namespace std;

#define INF pow(10,15)
#define  ll long long int

std::vector<std::vector<pair<int,int> >> adjlist(100010);
std::vector<int> parent(100010,-1);
std::vector<ll> dist(100010,INF);

void dijkstra(int source, int target)
{
	set<pair<ll,int> > S;
	S.insert(make_pair(0,source));
	dist[source]=0;

	while(!S.empty())
	{
		int current=S.begin()->second;
		if(current==target)
		{
			return;
		}
		S.erase(S.begin());

		for (int i = 0; i<adjlist[current].size(); ++i)
		{
			int to=adjlist[current][i].first;
			int weight=adjlist[current][i].second;

			if(weight+dist[current]<dist[to])
			{
				parent[to]=current;
				S.erase(make_pair(dist[to],to));
				dist[to]=weight+dist[current];
				S.insert(make_pair(dist[to],to));
			}
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

	int a,b,w;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b>>w;
		adjlist[a].push_back(make_pair(b,w));
		adjlist[b].push_back(make_pair(a,w));
	}

	dijkstra(1,n);

	std::vector<int> ans;

	if(dist[n]==INF)
	{
		cout<<"-1";
	}
	else
	{
		for (int i = n; i !=-1 ; i=parent[i])
		{
			ans.push_back(i);
		}
	}
	for (int i = ans.size()-1; i >=0 ; i--)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}