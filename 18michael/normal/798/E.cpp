#include<bits/stdc++.h>
using namespace std;
int n,edge_t=0,tot,p,a_t;
int la[14000002],deg[14000002],a[500002];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[42000002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[y];
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
	int num[2000002];
	inline void build(int k,int l,int r)
	{
		num[k]=(++tot);
		if(l==r)return add_edge(num[k],l);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),add_edge(num[k],num[ls]),add_edge(num[k],num[rs]);
	}
	inline void del(int k,int l,int r,int x)
	{
		if(l==r)return (void)(num[k]=0);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		num[k]=(++tot);
		if(x<=mid)del(ls,l,mid,x);
		else del(rs,mid+1,r,x);
		if(num[ls])add_edge(num[k],num[ls]);
		if(num[rs])add_edge(num[k],num[rs]);
	}
	inline void link(int k,int l,int r,int l1,int r1,int x)
	{
		if(!num[k] || l1>r1)return ;
		if(l>=l1 && r<=r1)return add_edge(x,num[k]);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(l1<=mid)link(ls,l,mid,l1,r1,x);
		if(r1>mid)link(rs,mid+1,r,l1,r1,x);
	}
}S;
inline void Topo()
{
	for(int i=1;i<=tot;++i)if(!deg[i])q.push(i);
	while(!q.empty())
	{
		p=q.front(),q.pop();
		if(p<=n)a[p]=a_t,--a_t;
		for(int i=la[p],v;i;i=edge[i].nx)if(!(--deg[v=edge[i].to]))q.push(v);
	}
}
int main()
{
	scanf("%d",&n),a_t=tot=n,S.build(1,1,n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(~x)add_edge(x,i),S.del(1,1,n,x);
		x=(~x? x:n),S.link(1,1,n,1,min(i-1,x),i),S.link(1,1,n,i+1,x,i);
	}
	Topo();
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}