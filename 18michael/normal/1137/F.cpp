#include<bits/stdc++.h>
using namespace std;
int n,q,t,tot,edge_t=0,las;
int la[200002],fa[200002],siz[200002],col[200002],lazcol[200002],deg[200002];
bool laz[200002];
int son[200002][2];
char s[12];
priority_queue<int,vector<int>,greater<int> > pq;
struct aaa
{
	int to,nx;
}edge[400002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[400002];
	inline void modify(int x,int d)
	{
		while(x<=tot)sum[x]+=d,x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}S;
inline bool IsRoot(int x)
{
	return x!=son[fa[x]][0] && x!=son[fa[x]][1];
}
inline bool Get(int x)
{
	return x==son[fa[x]][1];
}
inline void PushUp(int x)
{
	if(x)siz[x]=siz[son[x][0]]+siz[son[x][1]]+1;
}
inline void PushDown(int x)
{
	if(x)
	{
		if(laz[x])swap(son[x][0],son[x][1]),laz[son[x][0]]^=1,laz[son[x][1]]^=1,laz[x]=0;
		if(lazcol[x])lazcol[son[x][0]]=lazcol[son[x][1]]=col[son[x][0]]=col[son[x][1]]=lazcol[x],lazcol[x]=0;
	}
}
inline void Update(int x)
{
	if(!IsRoot(x))Update(fa[x]);
	PushDown(x);
}
inline void Rotate(int x)
{
	int y=fa[x],gx=Get(x),gy=Get(y),z=son[x][gx^1],w=fa[y];
	if(!IsRoot(y))son[w][gy]=x;
	fa[x]=w,fa[y]=x,son[x][gx^1]=y,fa[z]=y,son[y][gx]=z,PushUp(y),PushUp(x);
}
inline void Splay(int x)
{
	for(Update(x);!IsRoot(x);Rotate(x))if(!IsRoot(fa[x]))Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
inline int Access(int x)
{
	int p=0;
	for(;x;x=fa[p=x])Splay(x),S.modify(col[x],siz[son[x][1]]-siz[x]),son[x][1]=p,PushUp(x);
	return p;
}
inline void Topo()
{
	for(int i=1;i<=n;++i)if(deg[i]==1)pq.push(i);
	for(int p;pq.size();)
	{
		p=pq.top(),pq.pop(),S.modify(col[p]=(++t),siz[p]=1);
		for(int i=la[p],v;i;i=edge[i].nx)if((--deg[v=edge[i].to])==1)pq.push(v);
	}
}
inline void dfs(int x,int f)
{
	fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x);
}
inline int query(int x)
{
	return Splay(x),S.query(col[x]-1)+siz[x]-siz[son[x][0]];
}
int main()
{
	scanf("%d%d",&n,&q),tot=n+q;
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	Topo(),dfs(n,0);
	for(int x,y;q--;)
	{
		scanf("%s%d",s,&x);
		if(s[0]=='u')laz[Access(x)]^=1,Splay(x),S.modify(lazcol[x]=col[x]=(++t),siz[x]);
		else if(s[0]=='w')printf("%d\n",query(x));
		else scanf("%d",&y),printf("%d\n",query(x)<query(y)? x:y);
	}
	return 0;
}