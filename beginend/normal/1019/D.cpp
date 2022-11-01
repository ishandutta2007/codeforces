#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

typedef long long LL;

const int N=2005;
const double inf=1e18;

int n,tot,pos[N],id[N];
LL S;
struct point{int x,y;}p[N];
struct data{int x,y;double w;}a[N*N];

bool cmpx(point a,point b)
{
	return a.x<b.x;
}

bool cmpw(data a,data b)
{
	return a.w<b.w;
}

LL cross(point a,point b,point c)
{
	return fabs((LL)(a.x-c.x)*(b.y-c.y)-(LL)(a.y-c.y)*(b.x-c.x));
}

LL calc(int i,int j,int k)
{
	return cross(p[i],p[j],p[k]);
}

void pri(int i,int j,int k)
{
	printf("%d %d\n",p[i].x,p[i].y);
	printf("%d %d\n",p[j].x,p[j].y);
	printf("%d %d\n",p[k].x,p[k].y);
}

int main()
{
	scanf("%d%lld",&n,&S);
	for (int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
	std::sort(p+1,p+n+1,cmpx);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			a[++tot].x=i;a[tot].y=j;
			a[tot].w=(double)(p[j].y-p[i].y)/(p[j].x-p[i].x);
		}
	std::sort(a+1,a+tot+1,cmpw);
	double ans=inf;
	for (int i=1;i<=n;i++) pos[i]=id[i]=i;
	for (int i=1;i<=tot;i++)
	{
		int x=a[i].x,y=a[i].y;
		if (pos[x]>pos[y]) std::swap(x,y);
		int l=1,r=pos[x]-1;
		while (l<=r)
		{
			int mid=(l+r)/2;LL w=calc(id[mid],x,y);
			if (w==S*2) {puts("Yes");pri(id[mid],x,y);return 0;}
			if (w<S*2) r=mid-1;
			else l=mid+1;
		}
		l=pos[y]+1,r=n;
		while (l<=r)
		{
			int mid=(l+r)/2;LL w=calc(id[mid],x,y);
			if (w==S*2) {puts("Yes");pri(id[mid],x,y);return 0;}
			if (w<S*2) l=mid+1;
			else r=mid-1;
		}
		std::swap(pos[x],pos[y]);
		std::swap(id[pos[x]],id[pos[y]]);
	}
	puts("No");
	return 0;
}