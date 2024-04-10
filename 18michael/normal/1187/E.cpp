#include<cstdio>
#define LL long long
int n,edge_t=0;
int la[200002]={},fa[200002],size[200002];
LL f[200002],g[200002]={};
bool vis[200002]={},vis1[200002]={};
struct aaa
{
	int to,nx;
}edge[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int y)
{
	vis[x]=1,fa[x]=y,size[x]=1,f[x]=0;
	for(int i=la[x];i;i=edge[i].nx)
		if(!vis[edge[i].to])
			dfs(edge[i].to,x),size[x]+=size[edge[i].to],f[x]+=f[edge[i].to];
	f[x]+=size[x];
}
inline void dfs1(int x)
{
	vis1[x]=1,g[x]=max(g[x],g[fa[x]]+(n-size[x])-size[x]);
	for(int i=la[x];i;i=edge[i].nx)
		if(!vis1[edge[i].to])
			dfs1(edge[i].to);
}
inline void init()
{
	read(n);
	for(int i=1,x,y;i<n;++i)
		read(x),read(y),add_edge(x,y);
}
inline LL work()
{
	LL ans=0;dfs(1,1),vis1[1]=1,g[1]=f[1];
	for(int i=la[1];i;i=edge[i].nx)
		dfs1(edge[i].to);
	for(int i=1;i<=n;++i)
		ans=max(ans,g[i]);
	return ans;
}
int main()
{
	init(),printf("%lld",work());
	return 0;
}