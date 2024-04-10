#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,edge_t=0,dfn_t=0,n4,S=0,T,e_t=1,p;
int la[20002],fa[20002],dep[20002],siz[20002],son[20002],dfn[20002],top[20002],lae[100002],dis[100002],to[80002],pos[80002],num[20002];
bool vis[100002];
queue<int> q;
vector<int> vec;
struct aaa
{
	int to,nx,num;
}edge[40002];
struct bbb
{
	int to,nx,f;
}e[6000002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void add_e(int x,int y,int z)
{
	e[++e_t]=(bbb){y,lae[x],z},lae[x]=e_t;
	e[++e_t]=(bbb){x,lae[y],0},lae[y]=e_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x]=f,dep[x]=d,siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1),siz[x]+=siz[v],num[v]=edge[i].num;
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	top[to[dfn[x]=(++dfn_t)]=x]=t;
	if(son[x])dfs1(son[x],x,t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void build(int k,int l,int r)
{
	if(l==r)return pos[to[l]]=k,add_e(k,T,1);
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	add_e(k,ls,inf),add_e(k,rs,inf),build(ls,l,mid),build(rs,mid+1,r);
}
inline void add(int k,int l,int r,int l1,int r1,int x)
{
	if(l>=l1 && r<=r1)return add_e(x,k,inf);
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(l1<=mid)add(ls,l,mid,l1,r1,x);
	if(r1>mid)add(rs,mid+1,r,l1,r1,x);
}
inline bool Bfs()
{
	for(int i=1;i<=T;++i)dis[i]=inf;
	for(q.push(dis[0]=0);!q.empty();)
	{
		p=q.front(),q.pop();
		for(int i=lae[p],v;i;i=e[i].nx)
			if(e[i].f && dis[v=e[i].to]==inf)
				dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]<inf;
}
inline int Dfs(int x,int f)
{
	if(x==T)return f;
	int tmp,used=0;
	for(int i=lae[x],v;i;i=e[i].nx)
		if(e[i].f && dis[v=e[i].to]==dis[x]+1)
		{
			tmp=Dfs(v,min(f-used,e[i].f)),e[i].f-=tmp,e[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=inf;
	return used;
}
inline int Dinic()
{
	int maxflow=0;
	while(Bfs())maxflow+=Dfs(S,inf);
	return maxflow;
}
inline void dfs2(int x)
{
	vis[x]=1;
	for(int i=lae[x],v;i;i=e[i].nx)
		if(e[i].f && !vis[v=e[i].to])
			dfs2(v);
}
int main()
{
	scanf("%d%d",&n,&m),n4=(n<<2),T=n4+m+1;
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y,i);
	dfs(1,0,1),dfs1(1,0,1),build(1,1,n);
	for(int i=1,x,y;i<=m;++i)
	{
		for(scanf("%d%d",&x,&y),add_e(S,n4+i,1);top[x]!=top[y];x=fa[top[x]])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			add(1,1,n,dfn[top[x]],dfn[x],n4+i);
		}
		if(x^y)
		{
			if(dep[x]<dep[y])swap(x,y);
			add(1,1,n,dfn[y]+1,dfn[x],n4+i);
		}
	}
	printf("%d\n",Dinic()),dfs2(S);
	for(int i=1;i<=m;++i)if(!vis[n4+i])vec.push_back(i);
	printf("%d",vec.size());for(int i=0;i<vec.size();++i)printf(" %d",vec[i]);puts(""),vec.clear();
	for(int i=2;i<=n;++i)if(vis[pos[to[i]]])vec.push_back(num[to[i]]);
	printf("%d",vec.size());for(int i=0;i<vec.size();++i)printf(" %d",vec[i]);
	return 0;
}