#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,q,edge_t=0,e_t=0,dfn_t=0,st_t=0,tot,ans;
char ch;
int w[100002],la[100002],lae[200002],dfn[200002],low[100002],st[100002],siz[200002],son[200002],fa[200002],to[200002],top[200002],dep[200002];
bool ins[100002];
multiset<int> s[100002];
struct aaa
{
	int to,nx;
}edge[200002],e[400002];
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
	int mn[800002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(mn[k]=(to[l]<=n? w[to[l]]:*s[to[l]-n].begin()));
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),mn[k]=min(mn[ls],mn[rs]);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r)return (void)(mn[k]=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		mn[k]=min(mn[ls],mn[rs]);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return mn[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return min(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t;
	e[++e_t]=(aaa){x,lae[y]},lae[y]=e_t;
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x,ins[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(!dfn[v])
		{
			Tarjan(v),low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x])
			{
				add_e(x,++tot);
				do add_e(st[st_t],tot),--st_t;while(st[st_t+1]!=v);
			}
		}
		else if(ins[v])low[x]=min(low[x],dfn[v]);
	}
}
inline void dfs(int x,int f,int d)
{
	siz[x]=1,fa[x]=f,dep[x]=d;
	for(int i=lae[x],v;i;i=e[i].nx)
		if((v=e[i].to)!=f)
		{
			dfs(v,x,d+1),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	top[to[dfn[x]=(++dfn_t)]=x]=t;
	if(son[x])dfs1(son[x],x,t);
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f && v!=son[x])dfs1(v,x,v);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q),tot=n;
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	Tarjan(1),dfs(1,0,1),dfs1(1,dfn_t=0,1);
	for(int i=1;i<=n;++i)if(fa[i])s[fa[i]-n].insert(w[i]);
	S.build(1,1,tot);
	for(int x,y;q--;)
	{
		do ch=getchar();while(ch!='C' && ch!='A');
		scanf("%d%d",&x,&y);
		if(ch=='C')
		{
			if(fa[x])s[fa[x]-n].erase(s[fa[x]-n].lower_bound(w[x])),s[fa[x]-n].insert(y),S.modify(1,1,tot,dfn[fa[x]],*s[fa[x]-n].begin());
			S.modify(1,1,tot,dfn[x],w[x]=y);
		}
		else
		{
			for(ans=inf;top[x]!=top[y];ans=min(ans,S.query(1,1,tot,dfn[top[x]],dfn[x])),x=fa[top[x]])if(dep[top[x]]<dep[top[y]])swap(x,y);
			if(dfn[x]>dfn[y])swap(x,y);
			ans=min(ans,S.query(1,1,tot,dfn[x],dfn[y]));
			if(x>n)ans=min(ans,w[fa[x]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}