#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

const int N=300005;
const int inf=1000000;

int n,m,a[N],b[N];
struct tree{int tag,mx;}t[inf*4+5];

void pushdown(int d)
{
	int w=t[d].tag;t[d].tag=0;
	t[ls].tag+=w;t[ls].mx+=w;
	t[rs].tag+=w;t[rs].mx+=w;
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y) {t[d].tag+=z;t[d].mx+=z;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z);
	if (y>mid) ins(rs,mid+1,r,x,y,z);
	t[d].mx=std::max(t[ls].mx,t[rs].mx);
}

int query(int d,int l,int r)
{
	if (l==r) return l;
	pushdown(d);
	int mid=(l+r)/2;
	if (t[rs].mx>0) return query(rs,mid+1,r);
	else return query(ls,l,mid);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),ins(1,1,inf,1,a[i],1);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]),ins(1,1,inf,1,b[i],-1);
	int q;scanf("%d",&q);
	while (q--)
	{
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if (op==1)
		{
			ins(1,1,inf,1,a[x],-1);
			a[x]=y;
			ins(1,1,inf,1,a[x],1);
		}
		else
		{
			ins(1,1,inf,1,b[x],1);
			b[x]=y;
			ins(1,1,inf,1,b[x],-1);
		}
		if (t[1].mx<=0) printf("%d\n",-1);
		else printf("%d\n",query(1,1,inf));
	}
	return 0;
}