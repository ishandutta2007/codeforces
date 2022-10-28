#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int ans[N], vis[2][N], dist[2][N], ways[2][N];
vector<int> g[N];

void bfs(int k, int idx)
{
	queue<int> q;
	q.push(k);
	ways[idx][k]=1;
	vis[idx][k]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(!vis[idx][it])
			{
				dist[idx][it]=dist[idx][node]+1;
				vis[idx][it]=1;
				ways[idx][it]+=ways[idx][node];
				q.push(it);
			}
			else
			{
				if(dist[idx][node]+1==dist[idx][it])
				{
					ways[idx][it]+=ways[idx][node];
				}
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(1, 0);
	bfs(n, 1);
	int max1=0;
	for(int i=1;i<=n;i++)
	{
		if(dist[0][i]+dist[1][i]==dist[0][n])
		{
			int roads=1;
			if(i!=1 && i!=n)
				roads=2;
			int cur=roads*ways[0][i]*ways[1][i];
			if(cur>max1)
				max1=cur;
		}
	}
	int totways=ways[0][n];
	long double ans=(long double)max1/totways;
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}