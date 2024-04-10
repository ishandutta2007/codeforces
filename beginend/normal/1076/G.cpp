#include<bits/stdc++.h>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=200005;

int n,m,q,ans,a[N];
struct tree{int now,a[2][6],tag;}t[N*4];

void updata(int d)
{
	int k=t[d].now,x=t[ls].now,y=t[rs].now;
	for (int i=0;i<=m;i++) t[d].a[k][i]=t[ls].a[x][t[rs].a[y][i]];
	for (int i=0;i<=m;i++) t[d].a[k^1][i]=t[ls].a[x^1][t[rs].a[y^1][i]];
}

void pushdown(int d)
{
	if (!t[d].tag) return;
	t[d].tag^=1;
	t[ls].tag^=1;t[ls].now^=1;
	t[rs].tag^=1;t[rs].now^=1;
}

void build(int d,int l,int r)
{
	if (l==r)
	{
		for (int i=1;i<=m;i++) t[d].a[0][i]=t[d].a[1][i]=i-1;
		t[d].a[a[l]^1][0]=m;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	updata(d);
}

void rev(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) {t[d].now^=1;t[d].tag^=1;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) rev(ls,l,mid,x,y);
	if (y>mid) rev(rs,mid+1,r,x,y);
	updata(d);
}

void query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) {ans=t[d].a[t[d].now][ans];return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (y>mid) query(rs,mid+1,r,x,y);
	if (x<=mid) query(ls,l,mid,x,y);
}

int get(int d,int l,int r,int x)
{
	if (l==r) return t[d].now;
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) return get(ls,l,mid,x);
	else return get(rs,mid+1,r,x);
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	{
		LL x;scanf("%lld",&x);
		a[i]=x%2;
	}
	build(1,1,n);
	while (q--)
	{
		int op;scanf("%d",&op);
		if (op==1)
		{
			int l,r;LL d;scanf("%d%d%lld",&l,&r,&d);
			if (d&1) rev(1,1,n,l,r);
		}
		else
		{
			int l,r;scanf("%d%d",&l,&r);
			ans=0;
			if (l<r) query(1,1,n,l+1,r);
			int w=get(1,1,n,l)^a[l];
			if (ans||!ans&&!(w&1)) puts("1");
			else puts("2");
		}
	}
	return 0;
}