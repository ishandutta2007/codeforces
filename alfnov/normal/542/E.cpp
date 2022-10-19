#include<bits/stdc++.h>
using namespace std;
vector<int>g[1005];
int col[1005],q[1005],dist[1005],aa[1005];
bool dfs(int x)
{
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(col[cu])
		{
			if(col[x]==col[cu])return 1;
			continue;
		}
		col[cu]=-col[x];
		if(dfs(cu))return 1;
	}
	return 0;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!col[i])
	{
		col[i]=i;
		if(dfs(i))
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)dist[j]=0;
		int head=0,tail=-1,mx=1;
		q[++tail]=i,dist[i]=1;
		while(head<=tail)
		{
			int x=q[head++];
			for(int j=0;j<g[x].size();j++)
			{
				int cu=g[x][j];
				if(!dist[cu])
				{
					dist[cu]=dist[x]+1;
					mx=max(mx,dist[cu]);
					q[++tail]=cu;
				}
			}
		}
		int dd=abs(col[i]);
		aa[dd]=max(aa[dd],mx-1);
	}
	for(int i=1;i<=n;i++)ans=ans+aa[i];
	cout<<ans<<endl;
	return 0;
}