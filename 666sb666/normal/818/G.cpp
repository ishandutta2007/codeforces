#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3005,M=15005;
int n,a[N],f[7],g[100005],s,t,num,head[M],tot=-1;
struct E{int from,to,cap,flow,cost,next;}edge[M*30];
inline void addedge(int u,int v,int c,int w)
{
	edge[++tot]=(E){u,v,c,0,w,head[u]};head[u]=tot;
	edge[++tot]=(E){v,u,0,0,-w,head[v]};head[v]=tot;
}
int Q[M],p[M],d[M],vis[M];
inline bool SPFA(int&cost)
{
	int H=0,T=1;
	for(int i=1;i<=num;i++)p[i]=0,d[i]=1e9,vis[i]=0;
	Q[1]=s;d[s]=0;vis[s]=1;
	while(H!=T)
	{
		int x=Q[H=H%num+1];vis[x]=0;
		for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].cap>edge[i].flow&&d[x]+edge[i].cost<d[edge[i].to])
		{
			d[edge[i].to]=d[x]+edge[i].cost;p[edge[i].to]=i;
			if(!vis[edge[i].to])vis[edge[i].to]=1,Q[T=T%num+1]=edge[i].to;
		}
	}
	if(d[t]>=1e9)return false;
	int x=t,a=1e9;
	while(x!=s)a=min(a,edge[p[x]].cap-edge[p[x]].flow),x=edge[p[x]].from;
	x=t;
	while(x!=s)edge[p[x]].flow+=a,edge[p[x]^1].flow-=a,x=edge[p[x]].from;
	cost+=a*d[t];
	return true;
}
inline int mincostmaxflow()
{
	int cost=0;
	for(int i=0;i<4;i++)if(!SPFA(cost))return cost;
	return cost;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	s=4*n+1,t=4*n+2;num=t;
	for(int i=0;i<7;i++)f[i]=t;
	for(int i=0;i<=100001;i++)g[i]=t;
	for(int i=n;i>=1;i--)
	{
		int to=f[a[i]%7],from=4*(i-1)+3;f[a[i]%7]=from;
		addedge(from,to,1e9,0);
		addedge(from,4*(i-1)+1,1,0);
		addedge(4*(i-1)+2,to,1,0);
		to=g[a[i]],from=4*i;g[a[i]]=from;
		addedge(from,to,1e9,0);
		addedge(from,4*(i-1)+1,1,0);
		addedge(4*(i-1)+2,g[a[i]+1],1,0);
		addedge(4*(i-1)+2,g[a[i]-1],1,0);
	}
	for(int i=1;i<=n;i++)addedge(s,4*(i-1)+1,1,0),addedge(4*(i-1)+1,4*(i-1)+2,1,-1),addedge(4*(i-1)+2,t,1,0);
	printf("%d\n",-mincostmaxflow());
	return 0;
}