#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
set<int> g[N];
int a[N], vis[N], ways[N], dist[N];

void bfs(int k)
{
	queue<int> q;
	q.push(k);
	ways[k]=1;
	vis[k]=1;
	int idx=2;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		while(idx<=n && g[node].find(a[idx])!=g[node].end())
		{
			auto it=a[idx];
			if(!vis[it])
			{
				dist[it]=dist[node]+1;
				vis[it]=1;
				ways[it]+=ways[node];
				q.push(it);
			}
			else
			{
				if(dist[node]+1==dist[it])
				{
					ways[it]+=ways[node];
				}
			}
			idx++;
		}
		for(auto &it:g[node])
		{
			if(!vis[it])
			{
				cout<<"No";
				return;
			}
		}
	}
	if(idx==n+1)
		cout<<"Yes";
	else
		cout<<"No";
}


int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[1]!=1)
	{
		cout<<"No";
		return 0;
	}
	bfs(a[1]);
	return 0;
}