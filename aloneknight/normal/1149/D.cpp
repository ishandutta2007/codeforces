#include<bits/stdc++.h>
using namespace std;
const int N=75,M=405;
int n,m,A,B,cc,T,f[N],sz[N],id[N],dis[1<<18][N],hd[N],vis[1<<18][N];
struct st{int s,x;};queue<st>q;
struct E{int v,nxt,w;}e[M];
inline void add(int u,int v,int w){e[++cc]=(E){v,hd[u],w};hd[u]=cc;}
inline int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
inline bool cmn(int&a,int b){return a>b?(a=b,1):0;}
int main()
{
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);add(u,v,w);add(v,u,w);
		if(w==A){u=fnd(u);v=fnd(v);if(u!=v)f[u]=v,sz[v]+=sz[u];}
	}
	for(int i=1;i<=n;i++)if(f[i]==i&&sz[i]>3){for(int j=1;j<=n;j++)if(fnd(j)==i)id[j]=1<<T;T++;}
	memset(dis,0x3f,sizeof(dis));
	dis[id[1]][1]=0;q.push((st){id[1],1});
	while(!q.empty())
	{
		int s=q.front().s,x=q.front().x;q.pop();vis[s][x]=0;
		for(int i=hd[x];i;i=e[i].nxt)
		{
			int y=e[i].v,w=e[i].w;
			if(e[i].w==A)
			{
				if(cmn(dis[s][y],dis[s][x]+w)&&!vis[s][y])vis[s][y]=1,q.push((st){s,y});
			}
			else if(fnd(x)!=fnd(y)&&!(s&id[y]))
			{
				if(cmn(dis[s|id[y]][y],dis[s][x]+w)&&!vis[s|id[y]][y])vis[s|id[y]][y]=1,q.push((st){s|id[y],y});
			}
		}
	}
	putchar('0');
	for(int i=2,x;i<=n;i++)
	{
		x=0x3f3f3f3f;
		for(int s=0;s<(1<<T);s++)x=min(x,dis[s][i]);
		printf(" %d",x);
	}
	return 0;
}