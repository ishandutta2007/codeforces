#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,edge_t=1,S=0,T,p;
int la[1000002],val[1000002],dis[1000002],cur[1000002];
typedef pair<int,int> P;
vector<P> vecs[10002],vece[10002];
queue<int> q;
struct aaa
{
	int to,nx,f;
}edge[2000002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct SegTree
{
	int num[40002];
	inline void build(int k,int l,int r)
	{
		num[k]=(++T);
		if(l==r)return add_edge(num[k],l,1);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),add_edge(num[k],num[ls],val[num[ls]]=inf),add_edge(num[k],num[rs],val[num[rs]]=inf);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int o)
	{
		num[k]=(++T);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k),v;
		if(l>=l1 && r<=r1)return l<r? add_edge(num[k],num[ls],o*inf),add_edge(num[k],num[rs],o*inf):add_edge(num[k],l,o);
		v=val[num[ls]];
		if(l1<=mid)modify(ls,l,mid,l1,r1,o);
		add_edge(num[k],num[ls],val[num[ls]]=v),v=val[num[rs]];
		if(r1>mid)modify(rs,mid+1,r,l1,r1,o);
		add_edge(num[k],num[rs],val[num[rs]]=v);
	}
}Seg;
inline bool bfs()
{
	for(int i=0;i<=T;++i)dis[i]=inf,cur[i]=la[i];
	for(dis[S]=0,q.push(S);q.size();)
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)if(edge[i].f && dis[v=edge[i].to]>dis[p]+1)dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]<inf;
}
inline int dfs(int x,int f)
{
	if(x==T)return f;
	int tmp,used=0;
	for(int &i=cur[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(f-used,edge[i].f)),edge[i].f-=tmp,edge[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=0;
	return used;
}
inline int Dinic()
{
	int maxflow=0;
	while(bfs())maxflow+=dfs(S,inf);
	return maxflow;
}
int main()
{
	scanf("%d%d",&n,&m),T=n;
	for(int i=1,sx,sy,ex,ey;i<=m;++i)scanf("%d%d%d%d",&sx,&sy,&ex,&ey),vecs[sx].push_back(P(sy,ey)),vece[ex].push_back(P(sy,ey));
	Seg.build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<vecs[i].size();++j)Seg.modify(1,1,n,vecs[i][j].first,vecs[i][j].second,0);
		add_edge(S,Seg.num[1],1);
		for(int j=0;j<vece[i].size();++j)Seg.modify(1,1,n,vece[i][j].first,vece[i][j].second,1);
	}
	++T;
	for(int i=1;i<=n;++i)add_edge(i,T,1);
	return 0&printf("%d",Dinic());
}