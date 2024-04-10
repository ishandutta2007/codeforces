#include<cstdio>
#include<algorithm>
#define LL long long
#define eps 1e-12
using namespace std;
int n;LL T;
double mn[150002],mx[150002];
struct aaa
{
	int p,t;
	LL mn,mx;
	double v;
}a[150002]={};
inline bool cmp(aaa a,aaa b)
{
	return a.v>b.v? 1:0;
}
inline bool cmp1(aaa a,aaa b)
{
	return a.p<b.p? 1:0;
}
inline double Min(double a,double b)
{
	return a<b? a:b;
}
inline double Max(double a,double b)
{
	return a>b? a:b;
}
inline bool check(double c)
{
	for(int i=1;i<=n;++i)mn[i]=(1-c*a[i].mx/T)*a[i].p,mx[i]=(1-c*a[i].mn/T)*a[i].p;
	for(int i=1;i<n;++i)if(a[i+1].p-a[i].p<eps)mn[i+1]=min(mn[i],mn[i+1]),mx[i+1]=Max(mx[i],mx[i+1]);
	for(int i=n-1;i;--i)if(a[i+1].p-a[i].p<eps)mn[i]=min(mn[i],mn[i+1]),mx[i]=Max(mx[i],mx[i+1]);
	for(int i=1;i<n;++i)if(a[i].p<a[i+1].p && mx[i]>mn[i+1])return 0;
	return 1;
}
inline double binary_search()
{
	double l=0,r=1,mid;
	while(r-l>eps)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	return r;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].p);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].t),a[i].v=1.0*a[i].p/a[i].t;
	sort(a+1,a+n+1,cmp);
	for(int i=1,j;i<=n;i=j)
	{
		a[i].mx=a[i-1].mx;
		for(j=i;j<=n;++j)
		{
			if(a[i].v-a[j].v>eps)break;
			a[j].mn=a[i-1].mx+a[j].t,a[i].mx+=a[j].t;
		}
		for(int k=i+1;k<j;++k)a[k].mx=a[i].mx;
	}
	T=a[n].mx,sort(a+1,a+n+1,cmp1),printf("%.11lf",binary_search());
	return 0;
}