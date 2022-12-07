#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n,m;
struct qq
{
	int xl,xr,yl,yr,h;
	int id;
}a[N],tmp;
int ans[N];
struct qt
{
	int x,y;
	int id;
}p[N];
int num;
struct Tree
{
	int l,r;
	int xl,xr,yl,yr;
	int p;
	int s1,s2;
}tr[N];
int K;
bool cmp (qt x,qt y)	{return K==0?x.x<y.x:x.y<y.y;}
void upd (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	tr[now].xl=min(tr[s1].xl,tr[s2].xl);
	tr[now].xr=max(tr[s1].xr,tr[s2].xr);
	tr[now].yl=min(tr[s1].yl,tr[s2].yl);
	tr[now].yr=max(tr[s1].yr,tr[s2].yr);
	tr[now].p=min(tr[s1].p,tr[s2].p);
}
int id[N];
void bt (int l,int r,int d)
{
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	if (l==r) 
	{
		tr[now].xl=p[l].x;tr[now].xr=p[l].x;
		tr[now].yl=p[l].y;tr[now].yr=p[l].y;
		tr[now].p=p[l].id;
		return ;
	}
	int mid=(l+r)>>1;
	K=d;nth_element(p+l,p+mid,p+r+1,cmp);
	tr[now].s1=num+1;bt(l,mid,d^1);
	tr[now].s2=num+1;bt(mid+1,r,d^1);
	upd(now);
}
void query (int now)
{
	if (tr[now].p>=tmp.h || tmp.xr<tr[now].xl || tmp.xl>tr[now].xr || tmp.yr<tr[now].yl || tmp.yl>tr[now].yr) return ;
	if (tmp.xl<=tr[now].xl&&tmp.xr>=tr[now].xr&&tmp.yl<=tr[now].yl&&tmp.yr>=tr[now].yr)	{tmp.h=tr[now].p;return ;}
	query(tr[now].s1);
	query(tr[now].s2);
}
void Del (int now,int x)
{
	if (tr[now].l==tr[now].r)	{tr[now].p=m+1;return ;}
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) Del(tr[now].s1,x);
	else Del(tr[now].s2,x);
	tr[now].p=min(tr[tr[now].s1].p,tr[tr[now].s2].p);
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d%d%d%d%d",&a[u].xl,&a[u].xr,&a[u].yl,&a[u].yr,&a[u].h);
		a[u].id=u;
	}
	sort(a+1,a+1+n,[](qq x,qq y)
	{
		return x.h<y.h;
	});
	scanf("%d",&m);
	for (int u=1;u<=m;u++)
	{
		p[u].id=u;
		scanf("%d%d",&p[u].x,&p[u].y);		
	}
	bt(1,m,0);
	for (int u=1;u<=m;u++) id[p[u].id]=u;
	for (int u=1;u<=n;u++)
	{
		tmp=a[u];tmp.h=m+1;
		query(1);
		if (tmp.h==m+1) continue;
	//	printf("%d %d\n",a[u].h,tmp.h);
		ans[tmp.h]=a[u].id;
		Del(1,id[tmp.h]);
	}
	for (int u=1;u<=m;u++) printf("%d\n",ans[u]);
	return 0;
}