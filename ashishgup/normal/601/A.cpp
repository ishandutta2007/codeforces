#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=405;

int n, m;
int vis[N], level[N];
int g[N][N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	level[n]=-1;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u][v]=1;
		g[v][u]=1;
	}
	queue<int> q;
	q.push(1);
	vis[1]=1;
	level[1]=0;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if((!g[1][n]&&g[k][i])||(g[1][n]&&!g[k][i]))
			{
				if(!vis[i])
				{
					q.push(i);
					level[i]=level[k]+1;
					vis[i]=1;
				}
			}
		}
	}
	cout<<level[n];
}