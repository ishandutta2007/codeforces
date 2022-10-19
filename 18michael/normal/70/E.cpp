#include<cstdio>
#include<cstring>
#define inf 20000002
int n,m,edge_t=0;
int d[202],la[202]={},g[202],p[202],ans[202];//g[i]i,p[i]f[x][i]i 
int dis[202][202],f[202][202];//f[i][j]iji 
struct aaa
{
	int to,nx;
}edge[402];
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
	dis[x][y]=dis[y][x]=1;
}
inline void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			dis[i][j]=inf;
		dis[i][i]=0,g[i]=inf;
	}
	for(int i=1;i<n;++i)
		scanf("%d",&d[i]);
	for(int i=1,x,y;i<n;++i)
		scanf("%d%d",&x,&y),add_edge(x,y);
}
inline void Floyd()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
}
inline void dp(int x,int fa)
{
	for(int i=la[x];i;i=edge[i].nx)
		if(edge[i].to!=fa)
			dp(edge[i].to,x);
	for(int i=1;i<=n;++i)
	{
		f[x][i]=d[dis[x][i]];
		for(int j=la[x];j;j=edge[j].nx)
			if(edge[j].to!=fa)
				f[x][i]+=min(f[edge[j].to][i],m+g[edge[j].to]);
		if(f[x][i]<g[x])g[x]=f[x][i],p[x]=i;
	}
}
inline void getans(int x,int fa,int pos)
{
	for(int i=la[x],j;i;i=edge[i].nx)
		if((j=edge[i].to)!=fa)
		{
			if(m+g[j]>f[j][pos])ans[j]=pos;
			else ans[j]=p[j];
			getans(j,x,ans[j]);
		}
}
inline void print()
{
	printf("%d\n",m+g[1]);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
}
int main()
{
	init(),Floyd(),dp(1,0),getans(1,0,(ans[1]=p[1])),print();
	return 0;
}