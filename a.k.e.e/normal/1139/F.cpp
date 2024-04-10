#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=200005;

/*
Case #1:
	b[i]>=pref[j]				-b[i]<-pref[j]+1
	s[i]>=inc[j]				-s[i]<-inc[j]+1
	b[i]-pref[j]<=inc[j]-p[i]	b[i]+p[i]<inc[j]+pref[j]+1
Case #2:
	b[i]<pref[j]
	-s[i]<-inc[j]+1
	pref[j]-b[i]<=inc[j]-p[i]	p[i]-b[i]<inc[j]-pref[j]+1
*/

int n,m;
int p[MAXN],s[MAXN],b[MAXN],inc[MAXN],pref[MAXN];
int tmp[MAXN],ans[MAXN];
struct Data
{
	int ty,x,y,z,id;
	Data(){}
	Data(int ty,int x,int y,int z,int id):ty(ty),x(x),y(y),z(z),id(id){}
}a[MAXN],d[MAXN];
inline bool cmpx(Data a,Data b){return a.x==b.x?a.ty>b.ty:a.x<b.x;}
inline bool cmpy(Data a,Data b){return a.y==b.y?a.ty>b.ty:a.y<b.y;}

int c[MAXN];
void add(int x,int d)
	{for(int i=x;i<=n+m;i+=(i&-i))c[i]+=d;}
int query(int x)
	{int res=0;for(int i=x;i;i-=(i&-i))res+=c[i];return res;}
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	for(int i=l;i<=r;i++){d[i]=a[i];d[i].x=i;}
	sort(d+l,d+r+1,cmpy);
	for(int i=l;i<=r;i++)
		if(d[i].x<=mid && !d[i].ty)add(d[i].z,1);
		else if(d[i].x>mid && d[i].ty)ans[d[i].id]+=query(d[i].z-1);
	for(int i=l;i<=r;i++)
		if(d[i].x<=mid && !d[i].ty)add(d[i].z,-1);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)scanf("%d",&inc[i]);
	for(int i=1;i<=m;i++)scanf("%d",&pref[i]);
	
	for(int i=1;i<=n;i++)a[i]=Data(0,-b[i],-s[i],b[i]+p[i],i);
	for(int j=1;j<=m;j++)a[j+n]=Data(1,-pref[j]+1,-inc[j]+1,inc[j]+pref[j]+1,j+n);
	for(int i=1;i<=n+m;i++)tmp[i]=a[i].x;sort(tmp+1,tmp+n+m+1);for(int i=1;i<=n+m;i++)a[i].x=lower_bound(tmp+1,tmp+n+m+1,a[i].x)-tmp;
	for(int i=1;i<=n+m;i++)tmp[i]=a[i].y;sort(tmp+1,tmp+n+m+1);for(int i=1;i<=n+m;i++)a[i].y=lower_bound(tmp+1,tmp+n+m+1,a[i].y)-tmp;
	for(int i=1;i<=n+m;i++)tmp[i]=a[i].z;sort(tmp+1,tmp+n+m+1);for(int i=1;i<=n+m;i++)a[i].z=lower_bound(tmp+1,tmp+n+m+1,a[i].z)-tmp;
	sort(a+1,a+n+m+1,cmpx);
	solve(1,n+m);
	
	for(int i=1;i<=n;i++)a[i]=Data(0,b[i],-s[i],p[i]-b[i],i);
	for(int j=1;j<=m;j++)a[j+n]=Data(1,pref[j],-inc[j]+1,inc[j]-pref[j]+1,j+n);
	for(int i=1;i<=n+m;i++)tmp[i]=a[i].x;sort(tmp+1,tmp+n+m+1);for(int i=1;i<=n+m;i++)a[i].x=lower_bound(tmp+1,tmp+n+m+1,a[i].x)-tmp;
	for(int i=1;i<=n+m;i++)tmp[i]=a[i].y;sort(tmp+1,tmp+n+m+1);for(int i=1;i<=n+m;i++)a[i].y=lower_bound(tmp+1,tmp+n+m+1,a[i].y)-tmp;
	for(int i=1;i<=n+m;i++)tmp[i]=a[i].z;sort(tmp+1,tmp+n+m+1);for(int i=1;i<=n+m;i++)a[i].z=lower_bound(tmp+1,tmp+n+m+1,a[i].z)-tmp;
	sort(a+1,a+n+m+1,cmpx);
	solve(1,n+m);
	
	for(int j=n+1;j<=n+m;j++)printf("%d ",ans[j]);
	printf("\n");
	return 0;
}