#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

const int N=200005;

int n,q,a[N],tag[N*4];

void pushdown(int d)
{
	if (!tag[d]) return;
	int w=tag[d];tag[d]=0;
	tag[ls]=std::max(tag[ls],w);
	tag[rs]=std::max(tag[rs],w);
}

void ins(int d,int l,int r,int x,int y)
{
	if (l==r) {a[l]=y;tag[d]=0;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y);
	else ins(rs,mid+1,r,x,y);
}

void query(int d,int l,int r)
{
	if (l==r) {a[l]=std::max(a[l],tag[d]);return;}
	pushdown(d);
	int mid=(l+r)/2;
	query(ls,l,mid);
	query(rs,mid+1,r);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	while (q--)
	{
		int op;scanf("%d",&op);
		if (op==1)
		{
			int p,x;scanf("%d%d",&p,&x);
			ins(1,1,n,p,x);
		}
		else
		{
			int x;scanf("%d",&x);
			tag[1]=std::max(tag[1],x);
		}
	}
	query(1,1,n);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}