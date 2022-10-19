#include<cstdio>
#define inf 0x3f3f3f3f
int n,m,edge_t=0,mn;
int dis[602];
int val[602][602];
bool vis[602];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline void dijkstra(int x)
{
	for(int i=0;i<n;++i)dis[i]=val[x][i],vis[i]=0;
	for(int i=1;i<n;++i)
	{
		mn=n;for(int j=0;j<n;++j)if(!vis[j] && dis[j]<dis[mn])mn=j;
		vis[mn]=1;for(int j=0;j<n;++j)dis[(j+dis[mn])%n]=min(dis[(j+dis[mn])%n],dis[mn]+val[mn][j]);
		dis[(mn+1)%n]=min(dis[(mn+1)%n],dis[mn]+1);
	}
	dis[x]=0;
	for(int i=0;i<n;++i)printf("%d%c",dis[i],i+1==n? '\n':' ');
}
int main()
{
	scanf("%d%d",&n,&m),dis[n]=inf;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)val[i][j]=inf;
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),val[x][y]=z;
	for(int i=0;i<n;++i)dijkstra(i);
	return 0;
}