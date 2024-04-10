#include<bits/stdc++.h>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=100005;
const LL inf=(LL)1e18;

int n,p,a[N];
LL ans[N];
struct tree{LL mn,tag;}t[N*4];

void updata(int d)
{
	t[d].mn=std::min(t[ls].mn,t[rs].mn);
}

void mark(int d,LL w)
{
	t[d].mn=std::max(t[d].mn,w);
	t[d].tag=std::max(t[d].tag,w);
}

void pushdown(int d)
{
	LL w=t[d].tag;
	mark(ls,w);mark(rs,w);
}

void build(int d,int l,int r)
{
	if (l==r) {t[d].mn=a[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	updata(d);
}

int query(int d,int l,int r)
{
	if (l==r) return l;
	pushdown(d);
	int mid=(l+r)/2;
	if (t[ls].mn<=t[rs].mn) return query(ls,l,mid);
	else return query(rs,mid+1,r);
}

void modify(int d,int l,int r,int x,int y,LL w)
{
	if (x<=l&&r<=y) {mark(d,w);return;}
	int mid=(l+r)/2;
	if (x<=mid) modify(ls,l,mid,x,y,w);
	if (y>mid) modify(rs,mid+1,r,x,y,w);
	updata(d);
}

int main()
{
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	LL lst=0;
	for (int i=1;i<=n;i++)
	{
		int pos=query(1,1,n);
		ans[pos]=std::max(lst,(LL)a[pos]);
		lst=ans[pos]+p;
		if (pos<n) modify(1,1,n,pos+1,n,lst);
		modify(1,1,n,pos,pos,inf);
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]+p);
	return 0;
}