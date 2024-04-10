#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;
int X[500002],Y[500002];
LL ans[500002];
char ch[500002];
vector<int> vec[500002];
struct aaa
{
	int to,nx;
};
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
	int laz[4000002];
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return (void)(laz[k]=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])laz[ls]=laz[rs]=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
	}
	inline int query(int k,int l,int r,int x)
	{
		if(l==r)return laz[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])laz[ls]=laz[rs]=laz[k],laz[k]=0;
		if(x<=mid)return query(ls,l,mid,x);
		return query(rs,mid+1,r,x);
	}
};
inline int lowbit(int x)
{
	return x&(-x);
}
struct bbb
{
	int tot,edge_t,dfn_t,t;
	SegTree S;
	int rt[1000002],rtsiz[1000002],la[1000002],dfn[1000002],siz[1000002],deg[1000002];
	LL sum[1000002];
	aaa edge[1000002];
	inline void modify(int x,int d)
	{
		while(x<=t)sum[x]+=d,x+=lowbit(x);
	}
	inline LL query(int x)
	{
		LL res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
	inline void add_edge(int x,int y)
	{
		edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[y];
	}
	inline void init(int x)
	{
		tot=x;
		for(int i=1;i<=x;++i)rt[i]=i,rtsiz[i]=1;
	}
	inline void getroot(int x)
	{
		if(x==rt[x])return ;
		getroot(rt[x]),rt[x]=rt[rt[x]];
	}
	inline void dfs(int x)
	{
		dfn[x]=(++dfn_t),siz[x]=1;
		for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to),siz[x]+=siz[v];
	}
	inline void get()
	{
		for(int i=1;i<=tot;++i)if(!deg[i])dfs(i);
	}
}a[2];
int main()
{
	scanf("%d%d",&n,&m),a[0].init(n),a[1].init(n);
	for(int i=1;i<=m;++i)
	{
		do ch[i]=getchar();while(ch[i]!='U' && ch[i]!='M' && ch[i]!='A' && ch[i]!='Z' && ch[i]!='Q');
		scanf("%d",&X[i]);
		if(ch[i]=='U')
		{
			scanf("%d",&Y[i]),a[0].getroot(X[i]),a[0].getroot(Y[i]);
			if(a[0].rt[X[i]]^a[0].rt[Y[i]])++a[0].tot,a[0].add_edge(a[0].tot,a[0].rt[X[i]]),a[0].add_edge(a[0].tot,a[0].rt[Y[i]]),
			a[0].rtsiz[a[0].tot]=a[0].rtsiz[a[0].rt[X[i]]]+a[0].rtsiz[a[0].rt[Y[i]]],a[0].rt[a[0].rt[X[i]]]=a[0].rt[a[0].rt[Y[i]]]=a[0].rt[a[0].tot]=a[0].tot;
		}
		else if(ch[i]=='M')
		{
			scanf("%d",&Y[i]),a[1].getroot(X[i]),a[1].getroot(Y[i]);
			if(a[1].rt[X[i]]^a[1].rt[Y[i]])++a[1].tot,a[1].add_edge(a[1].tot,a[1].rt[X[i]]),a[1].add_edge(a[1].tot,a[1].rt[Y[i]]),
			a[1].rtsiz[a[1].tot]=a[1].rtsiz[a[1].rt[X[i]]]+a[1].rtsiz[a[1].rt[Y[i]]],a[1].rt[a[1].rt[X[i]]]=a[1].rt[a[1].rt[Y[i]]]=a[1].rt[a[1].tot]=a[1].tot;
		}
	}
	a[0].get(),a[1].get(),a[0].t=a[0].tot,a[1].t=a[1].tot,a[0].init(n),a[1].init(n);
	for(int i=1;i<=m;++i)
	{
		if(ch[i]=='M')
		{
			a[1].getroot(X[i]),a[1].getroot(Y[i]);
			if(a[1].rt[X[i]]^a[1].rt[Y[i]])++a[1].tot,a[1].rtsiz[a[1].tot]=a[1].rtsiz[a[1].rt[X[i]]]+a[1].rtsiz[a[1].rt[Y[i]]],
			a[1].rt[a[1].rt[X[i]]]=a[1].rt[a[1].rt[Y[i]]]=a[1].rt[a[1].tot]=a[1].tot;
		}
		else if(ch[i]=='Z')a[1].getroot(X[i]),a[1].S.modify(1,1,a[1].t,a[1].dfn[a[1].rt[X[i]]],a[1].dfn[a[1].rt[X[i]]]+a[1].siz[a[1].rt[X[i]]]-1,i);
		else if(ch[i]=='Q')vec[a[1].S.query(1,1,a[1].t,a[1].dfn[X[i]])].push_back(i);
	}
	for(int i=1;i<=m;++i)
	{
		if(ch[i]=='U')
		{
			a[0].getroot(X[i]),a[0].getroot(Y[i]);
			if(a[0].rt[X[i]]^a[0].rt[Y[i]])++a[0].tot,a[0].rtsiz[a[0].tot]=a[0].rtsiz[a[0].rt[X[i]]]+a[0].rtsiz[a[0].rt[Y[i]]],
			a[0].rt[a[0].rt[X[i]]]=a[0].rt[a[0].rt[Y[i]]]=a[0].rt[a[0].tot]=a[0].tot;
		}
		else if(ch[i]=='A')a[0].getroot(X[i]),a[0].modify(a[0].dfn[a[0].rt[X[i]]],a[0].rtsiz[a[0].rt[X[i]]]),
			a[0].modify(a[0].dfn[a[0].rt[X[i]]]+a[0].siz[a[0].rt[X[i]]],-a[0].rtsiz[a[0].rt[X[i]]]);
		else if(ch[i]=='Z')for(int j=0;j<vec[i].size();++j)ans[vec[i][j]]=-a[0].query(a[0].dfn[X[vec[i][j]]]);
		else if(ch[i]=='Q')ans[i]+=a[0].query(a[0].dfn[X[i]]),printf("%lld\n",ans[i]);
	}
	return 0;
}