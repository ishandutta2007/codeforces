#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=200010;
const int INF=1e9+7;
struct Seg
{
	ll sum;
	int minx,numx;
	int secx;
	int tag;
}	seg[maxn<<2];
int a[maxn];
int n,m;
void update(int t)
{
	seg[t].sum=seg[t<<1].sum+seg[t<<1|1].sum;
	seg[t].minx=min(seg[t<<1].minx,seg[t<<1|1].minx);
	seg[t].numx=0;
	if (seg[t].minx==seg[t<<1].minx)	seg[t].numx+=seg[t<<1].numx;
	if (seg[t].minx==seg[t<<1|1].minx)	seg[t].numx+=seg[t<<1|1].numx;
	seg[t].secx=min(seg[t<<1].secx,seg[t<<1|1].secx);
	if (seg[t<<1].minx!=seg[t].minx)	seg[t].secx=min(seg[t].secx,seg[t<<1].minx);
	if (seg[t<<1|1].minx!=seg[t].minx)	seg[t].secx=min(seg[t].secx,seg[t<<1|1].minx);
}
void tag(int t,int y)
{
	if (seg[t].minx>=y)	return;
	if (seg[t].secx>y)
	{
		seg[t].sum+=(ll)(y-seg[t].minx)*seg[t].numx;
		seg[t].minx=y;
		seg[t].tag=y;
		return;
	}
	tag(t<<1,y);
	tag(t<<1|1,y);
	update(t);
}
void push_down(int t)
{
	if (seg[t].tag==0)	return;
	tag(t<<1,seg[t].tag);
	tag(t<<1|1,seg[t].tag);
	seg[t].tag=0;
}
void build(int t,int l,int r)
{
	if (l==r)
	{
		seg[t].sum=seg[t].minx=a[l];
		seg[t].numx=1;
		seg[t].secx=INF;
		seg[t].tag=0;
		return;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	update(t);
}
void change(int t,int l,int r,int pos,int y)
{
	if (l==r)
	{
		seg[t].sum=y;
		seg[t].minx=y;
		seg[t].secx=INF;
		seg[t].numx=1;
		seg[t].tag=0;
		return;
	}
	push_down(t);
	int mid=(l+r)>>1;
	if (pos<=mid)	change(t<<1,l,mid,pos,y);
	else change(t<<1|1,mid+1,r,pos,y);
	update(t);
}
void getans(int t,int l,int r)
{
	if (l==r)
	{
		printf("%d ",seg[t].minx);
		return;
	}
	push_down(t);
	int mid=(l+r)>>1;
	getans(t<<1,l,mid);
	getans(t<<1|1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d%d",&x,&y);
			change(1,1,n,x,y);
		}	else
		{
			scanf("%d",&x);
			tag(1,x);
		}
	}
	getans(1,1,n);
	return 0;
}