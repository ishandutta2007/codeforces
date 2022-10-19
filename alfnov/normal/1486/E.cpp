#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
struct dij
{
	int x,a;
	long long dist;
	dij(int x=0,int a=0,long long dist=0):x(x),a(a),dist(dist){}
	bool operator<(const dij &other)const
	{
		return dist>other.dist;
	}
};
priority_queue<dij>pq;
vector<long long>g[51][100005];
vector<pair<int,int> >gg[100005];
int vist[55][100005];
long long dist[55][100005];
long long yasuo(int a,int b,int c)
{
	return (c*100+b)*200000ll+a;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		gg[u].push_back(mk(v,w));
		gg[v].push_back(mk(u,w));
	}
	for(int i=1;i<=n;i++)for(int j=0;j<gg[i].size();j++)
	{
		int c1=gg[i][j].first,c2=gg[i][j].second;
		g[0][i].push_back(yasuo(c1,c2,0));
		for(int w=1;w<=50;w++)
			g[w][i].push_back(yasuo(c1,0,(w+c2)*(w+c2)));
	}
	memset(dist,63,sizeof(dist));
	dist[0][1]=0,pq.push(dij(1,0,0));
	while(pq.size())
	{
		int x,w;
		do
		{
			dij d=pq.top();
			pq.pop(),x=d.x,w=d.a;
		}while(vist[w][x]&&pq.size());
		if(vist[w][x])break;
		vist[w][x]=1;
		for(int i=0;i<g[w][x].size();i++)
		{
			long long aa=g[w][x][i];
			int dx=aa%200000,dw=aa/200000%100,v=aa/20000000;
			if(dist[dw][dx]>dist[w][x]+v)
			{
				dist[dw][dx]=dist[w][x]+v;
				if(!vist[dw][dx])pq.push(dij(dx,dw,dist[dw][dx]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dist[0][i]>1e15)printf("-1 ");
		else printf("%d ",dist[0][i]);
	}
	return 0;
}