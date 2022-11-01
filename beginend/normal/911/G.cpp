#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;

int n,m,sx,sy,now,ans[N],sz,rt[105];
struct tree{int l,r;}t[N*20];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void ins(int &d,int l,int r,int x)
{
	if (!d) d=++sz;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
}

int merge(int x,int y)
{
	if (!x||!y) return x+y;
	t[x].l=merge(t[x].l,t[y].l);
	t[x].r=merge(t[x].r,t[y].r);
	return x;
}

void modify(int &d,int &p,int l,int r)
{
	if (!d) return;
	if (sx<=l&&r<=sy) {p=merge(d,p);d=0;return;}
	if (!p) p=++sz;
	int mid=(l+r)/2;
	if (sx<=mid) modify(t[d].l,t[p].l,l,mid);
	if (sy>mid) modify(t[d].r,t[p].r,mid+1,r);
}

void solve(int x,int l,int r)
{
	if (!x) return;
	if (l==r) {ans[l]=now;return;}
	int mid=(l+r)/2;
	solve(t[x].l,l,mid);solve(t[x].r,mid+1,r);
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		ins(rt[x],1,n,i);
	}
	m=read();
	while (m--)
	{
		sx=read();sy=read();int x=read(),y=read();
		if (x!=y) modify(rt[x],rt[y],1,n);
	}
	for (int i=1;i<=100;i++) now=i,solve(rt[i],1,n);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}