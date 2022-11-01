#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=200005;

int n,T;
double ans[N];
struct data{int a,t;}a[N];

bool cmp(data a,data b)
{
	return a.t<b.t;
}

int main()
{
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].a);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].t),a[i].t-=T;
	LL s=0;
	for (int i=1;i<=n;i++) s+=(LL)a[i].t*a[i].a;
	sort(a+1,a+n+1,cmp);
	if (s>0)
	{
		for (int i=n;i>=1;i--)
		{
			if (a[i].t<=0) {ans[i]=a[i].a;continue;}
			if (s>=(LL)a[i].t*a[i].a) s-=(LL)a[i].t*a[i].a;
			else ans[i]=(double)a[i].a-(double)s/a[i].t,s=0;
		}
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i].t>=0) {ans[i]=a[i].a;continue;}
			if (s<=(LL)a[i].t*a[i].a) s-=(LL)a[i].t*a[i].a;
			else ans[i]=(double)a[i].a-(double)s/a[i].t,s=0;
		}
	}
	if (s!=0) {puts("0");return 0;}
	double w=0;
	for (int i=1;i<=n;i++) w+=ans[i];
	printf("%.10lf",w);
	return 0;
}