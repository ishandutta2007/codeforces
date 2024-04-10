#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int N=400005;
pair<int,int> t[N*4];
int n,m;
int l[N],r[N],x[N],opt[N],g[N],cov[N*4];
inline pair<int,int> mx(pair<int,int> a,pair<int,int> b)
{
	if (a.first>b.first)
		return {a.first,max(a.second,b.first)};
	else
		return {b.first,max(a.first,b.second)};
}
inline void build(int x,int l,int r)
{
	if (l==r)
	{
		t[x]={inf,0};
	}
	else
	{
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		t[x]=mx(t[x*2],t[x*2+1]);
	}
}
inline void modify(int x,int l,int r,int L,int R,int y)
{
	if (l==L&&r==R)
	{
		if (l==r)
		{
			cov[x]=0;
			t[x]={y,0};
		}
		else
		{
			t[x]={y,y};
			cov[x]=y;
		}
		return;
	}
	int mid=(l+r)/2;
	if (cov[x])
	{
		cov[x*2]=cov[x*2+1]=cov[x];
		if (l==mid)
			t[x*2]={cov[x],0};
		else
			t[x*2]={cov[x],cov[x]};
		if (mid+1==r)
			t[x*2+1]={cov[x],0};
		else
			t[x*2+1]={cov[x],cov[x]};
		cov[x]=0;
	}
	if (R<=mid)
		modify(x*2,l,mid,L,R,y);
	if (L>mid)
		modify(x*2+1,mid+1,r,L,R,y);
	if (L<=mid&&R>mid)
	{
		modify(x*2,l,mid,L,mid,y);
		modify(x*2+1,mid+1,r,mid+1,R,y);
	}
	t[x]=mx(t[x*2],t[x*2+1]);
}
inline void mn(int &x,int y)
{
	if (x>y)
		x=y;
}
inline pair<int,int> ask(int x,int l,int r,int L,int R)
{
	if (l==L&&r==R)
		return t[x];
	int mid=(l+r)/2;
	if (cov[x])
	{
		cov[x*2]=cov[x*2+1]=cov[x];
		if (l==mid)
			t[x*2]={cov[x],0};
		else
			t[x*2]={cov[x],cov[x]};
		if (mid+1==r)
			t[x*2+1]={cov[x],0};
		else
			t[x*2+1]={cov[x],cov[x]};
		cov[x]=0;
	}
	if (R<=mid)
		return ask(x*2,l,mid,L,R);
	if (L>mid)
		return ask(x*2+1,mid+1,r,L,R);
	return mx(ask(x*2,l,mid,L,mid),ask(x*2+1,mid+1,r,mid+1,R));
}
inline int findinf(int x,int l,int r,int L,int R)
{
	if (t[x].first!=inf)
		return 0;
	if (l==r&&t[x].first==inf)
		return l;
	if (l==r)
		return 0;
	int mid=(l+r)/2;
	if (cov[x])
	{
		cov[x*2]=cov[x*2+1]=cov[x];
		if (l==mid)
			t[x*2]={cov[x],0};
		else
			t[x*2]={cov[x],cov[x]};
		if (mid+1==r)
			t[x*2+1]={cov[x],0};
		else
			t[x*2+1]={cov[x],cov[x]};
		cov[x]=0;
	}
	if (R<=mid)
		return findinf(x*2,l,mid,L,R);
	if (L>mid)
		return findinf(x*2+1,mid+1,r,L,R);
	return findinf(x*2,l,mid,L,mid)+findinf(x*2+1,mid+1,r,mid+1,R);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&opt[i]);
		if (opt[i]==0)
			scanf("%d%d%d",&l[i],&r[i],&x[i]);
		else
			scanf("%d",&x[i]);
	}
	for (int i=0;i<=n+1;++i)
		g[i]=inf;
	for (int i=m;i;--i)
		if (opt[i]==0&&x[i]==0)
		{
			modify(1,1,n,l[i],r[i],i);
		}
	for (int i=1;i<=m;++i)
		if (opt[i]==0)
		{
			if (x[i]==1)
			{
				pair<int,int> jg=ask(1,1,n,l[i],r[i]);
				if (jg.first==inf&&jg.second!=inf)
					mn(g[findinf(1,1,n,l[i],r[i])],max(i,jg.second));
			}
		}
		else
		{
			if (g[x[i]]<i)
				puts("YES");
			else
			{
				// if (g[x[i]]!=inf)
				// {
				// 	puts("N/A");
				// 	continue;
				// }
				pair<int,int> jg=ask(1,1,n,x[i],x[i]);
				if (jg.first>i)
					puts("N/A");
				else
					puts("NO");
			}
		}
	return 0;
}