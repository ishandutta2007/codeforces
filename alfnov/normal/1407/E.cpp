#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >g[500005];
int q[500005],dd[500005],dist[500005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[v].push_back(make_pair(u,w));
	}
	int head=0,tail=-1;
	memset(dist,63,sizeof(dist));
	memset(dd,-1,sizeof(dd));
	dist[n]=0,dd[n]=1;
	q[++tail]=n;
	while(head<=tail)
	{
		int x=q[head++];
		for(int i=0;i<g[x].size();i++)
		{
			int cu=g[x][i].first,c2=g[x][i].second;
			if(dd[cu]==-1)
			{
				dd[cu]=!c2;
				continue;
			}
			if(dd[cu]==c2)
			{
				if(dist[cu]>dist[x]+1)
				{
					dist[cu]=dist[x]+1;
					q[++tail]=cu; 
				}
			}
		}
	}
	if(dist[1]>1e9)cout<<-1<<endl;
	else cout<<dist[1]<<endl;
	for(int i=1;i<=n;i++)if(dd[i]==-1)dd[i]=1;
	for(int i=1;i<=n;i++)cout<<dd[i];
	return 0;
}