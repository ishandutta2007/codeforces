#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define GC getchar()
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
typedef long long LL;
const int N=2e5+5,M=3e5+5;
struct E{int to,v,next;}edge[M<<1];
int n,m,s,head[N],tot,vis[N],id[N],cnt,fa[N][20],dep[N],sz[N],ans;
LL dis[N];
priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > > Q;
inline void Dij()
{
	for(int i=1;i<=n;i++)dis[i]=1e18,vis[i]=0;
	dis[s]=0;Q.push(make_pair(0ll,s));
	while(!Q.empty())
	{
		int x=Q.top().second;Q.pop();
		if(vis[x])continue;
		vis[x]=1;id[++cnt]=x;
		for(int i=head[x];i!=-1;i=edge[i].next)if(dis[x]+edge[i].v<dis[edge[i].to])
			Q.push(make_pair(dis[edge[i].to]=dis[x]+edge[i].v,edge[i].to));
	}
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(dep[x]-dep[y]>=(1<<i))x=fa[x][i];
	for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	if(x!=y)x=fa[x][0],y=fa[y][0];
	return x;
}
int main()
{
	memset(head,-1,sizeof(head));
	read(n),read(m),read(s);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;read(x),read(y),read(z);
		edge[++tot]=(E){y,z,head[x]};head[x]=tot;
		edge[++tot]=(E){x,z,head[y]};head[y]=tot;
	}
	Dij();
	fa[s][0]=0;dep[s]=1;
	for(int i=2;i<=n;i++)if(dis[id[i]]<1e18)
	{
		int l=0,x=id[i];
		for(int j=head[x];j!=-1;j=edge[j].next)if(dis[edge[j].to]+edge[j].v==dis[x])
			l=l?lca(l,edge[j].to):edge[j].to;
		fa[x][0]=l;dep[x]=dep[l]+1;
		for(int j=1;j<20;j++)fa[x][j]=fa[fa[x][j-1]][j-1];
	}
	for(int i=1;i<=n;i++)sz[i]=1;
	for(int i=n;i>=2;i--)if(dis[id[i]]<1e18)
	{
		int x=id[i];
		sz[fa[x][0]]+=sz[x];
		if(sz[x]>ans)ans=sz[x];
	}
	printf("%d\n",ans);
	return 0;
}