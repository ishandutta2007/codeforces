#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=300005;
const int inf=1e9;

int n,a[N],last[N],app[N],sta[N];
struct tree{int mn1,mn2,s1,s2,tag;}t[N*4];

void pushdown(int d)
{
	int w=t[d].tag;t[d].tag=0;
	t[ls].mn1+=w;t[ls].mn2+=w;t[ls].tag+=w;
	t[rs].mn1+=w;t[rs].mn2+=w;t[rs].tag+=w;
}

void updata(int d)
{
	t[d]=t[ls];t[d].tag=0;
	if (t[rs].mn1<t[d].mn1) t[d].mn2=t[d].mn1,t[d].s2=t[d].s1,t[d].mn1=t[rs].mn1,t[d].s1=t[rs].s1;
	else if (t[rs].mn1==t[d].mn1) t[d].s1+=t[rs].s1;
	else if (t[rs].mn1<t[d].mn2) t[d].mn2=t[rs].mn1,t[d].s2=t[rs].s1;
	else if (t[rs].mn1==t[d].mn2) t[d].s2+=t[rs].s1;
	if (t[rs].mn2<t[d].mn2) t[d].mn2=t[rs].mn2,t[d].s2=t[rs].s2;
	else if (t[rs].mn2==t[d].mn2) t[d].s2+=t[rs].s2;
}

void build(int d,int l,int r,int x,int y)
{
	if (l==r)
	{
		t[d].mn1=y;t[d].s1=1;
		t[d].mn2=inf;t[d].s2=0;
		return;
	}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) build(ls,l,mid,x,y);
	else build(rs,mid+1,r,x,y);
	updata(d);
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y)
	{
		t[d].mn1+=z;t[d].mn2+=z;t[d].tag+=z;
		return;
	}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z);
	if (y>mid) ins(rs,mid+1,r,x,y,z);
	updata(d);
}

int query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return !t[d].mn1?t[d].s1:0;
	pushdown(d);
	int ans=0,mid=(l+r)/2;
	if (x<=mid) ans+=query(ls,l,mid,x,y);
	if (y>mid) ans+=query(rs,mid+1,r,x,y);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),last[i]=app[a[i]],app[a[i]]=i;
	int top=0,lim=0;
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		lim=std::max(lim,last[i]);
		if (lim+1<=i-1) ins(1,1,n,lim+1,i-1,-1);
		while (top&&a[sta[top]]<a[i])
		{
			top--;
			if (sta[top+1]<=lim) continue;
			ins(1,1,n,std::max(lim+1,sta[top]+1),sta[top+1],a[i]-a[sta[top+1]]);
		}
		build(1,1,n,i,a[i]-1);
		sta[++top]=i;
		ans+=query(1,1,n,lim+1,i);
	}
	printf("%lld\n",ans);
	return 0;
}