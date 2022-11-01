#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX(x,y) x=max(x,y)
using namespace std;

typedef long long LL;

const int N=500005;
const int inf=1000000000;

int n,p,q,r,mx1[N],mx2[N];
struct data{int x,y;}a[N];
vector<int> vec[N];
struct tree{int len,mx,mn1,s1,mn2,s2,tag;LL s;}t[N*4];

void updata(int d)
{
	int l=d*2,r=d*2+1;
	t[d].s=t[l].s+t[r].s;
	t[d].mx=max(t[l].mx,t[r].mx);
	t[d].mn1=t[l].mn1;t[d].s1=t[l].s1;t[d].mn2=t[l].mn2;t[d].s2=t[l].s2;
	if (t[r].mn1<t[d].mn1) t[d].mn2=t[d].mn1,t[d].s2=t[d].s1,t[d].mn1=t[r].mn1,t[d].s1=t[r].s1;
	else if (t[r].mn1==t[d].mn1) t[d].s1+=t[r].s1;
	else if (t[r].mn1<t[d].mn2) t[d].mn2=t[r].mn1,t[d].s2=t[r].s1;
	if (t[r].mn2<t[d].mn2) t[d].mn2=t[r].mn2,t[d].s2=t[r].s2;
	else if (t[r].mn2==t[d].mn2) t[d].s2+=t[r].s2;
}

void mark(int d,int w)
{
	if (w<=t[d].mn1) return;
	t[d].s+=(LL)t[d].s1*(w-t[d].mn1);
	t[d].mn1=w;MAX(t[d].tag,w);
	MAX(t[d].mx,w);
}

void pushdown(int d)
{
	if (!t[d].tag) return;
	int w=t[d].tag;t[d].tag=0;
	mark(d*2,w);mark(d*2+1,w);
}

void build(int d,int l,int r)
{
	t[d].len=r-l+1;
	if (l==r) {t[d].s1=1;t[d].mn2=inf;return;}
	int mid=(l+r)/2;
	build(d*2,l,mid);build(d*2+1,mid+1,r);
	updata(d);
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (z<=t[d].mn1) return;
	if (l<r) pushdown(d);
	int mid=(l+r)/2;
	if (l==x&&r==y)
	{
		if (z<t[d].mn2) {mark(d,z);return;}
		ins(d*2,l,mid,x,mid,z);
		ins(d*2+1,mid+1,r,mid+1,y,z);
		updata(d);
		return;
	}
	if (x<=mid) ins(d*2,l,mid,x,min(y,mid),z);
	if (y>mid) ins(d*2+1,mid+1,r,max(x,mid+1),y,z);
	updata(d);
}

LL query(int d,int l,int r,int x,int y,int z)
{
	if (t[d].mx<z) return 0;
	if (l<r) pushdown(d);
	int mid=(l+r)/2;
	if (l==x&&r==y)
	{
		if (t[d].mn1>=z) return t[d].s-(LL)(z-1)*t[d].len;
		return query(d*2,l,mid,x,mid,z)+query(d*2+1,mid+1,r,mid+1,y,z);
	}
	LL ans=0;
	if (x<=mid) ans+=query(d*2,l,mid,x,min(y,mid),z);
	if (y>mid) ans+=query(d*2+1,mid+1,r,max(x,mid+1),y,z);
	return ans;
}

int main()
{
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d%d%d",&x,&a[i].x,&a[i].y);
		vec[x].push_back(i);
		MAX(mx1[x],a[i].x);
		MAX(mx2[x],a[i].y);
	}
	for (int i=p;i>=1;i--) MAX(mx1[i],mx1[i+1]),MAX(mx2[i],mx2[i+1]);
	LL ans=0;
	build(1,1,q);
	for (int i=1;i<=p;i++)
	{
		for (int j=0;j<vec[i].size();j++)
			ins(1,1,q,1,a[vec[i][j]].x,a[vec[i][j]].y);
		int lx=mx1[i]+1,ly=mx2[i]+1;
		ans+=(LL)(q-lx+1)*(r-ly+1)-query(1,1,q,lx,q,ly);
	}
	printf("%I64d",ans);
	return 0;
}