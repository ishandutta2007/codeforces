#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=300005;
struct node
{
	int p,t;
	long long l,r;
}a[N];
int n,i,j,k;
double lt,rt,mid,mx,u;
long long w,sum,s[N];
bool cmp(node a,node b)
{
	return 1ll*a.t*b.p<1ll*b.t*a.p;
}
bool cmq(node a,node b)
{
	return a.p<b.p;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i].p);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i].t);
		sum+=a[i].t;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i)
		s[i]=s[i-1]+a[i].t;
	for(i=1;i<=n;i=j)
	{
		for(k=i;k<=n&&1ll*a[i].t*a[k].p==1ll*a[k].t*a[i].p;++k);
		for(j=i;j<=n&&1ll*a[i].t*a[j].p==1ll*a[j].t*a[i].p;++j)
			a[j].l=s[i-1]+a[j].t,a[j].r=s[k-1];
	}
	sort(a+1,a+1+n,cmq);
	lt=0,rt=1;
	while(rt-lt>=1e-8)
	{
		mid=(lt+rt)/2;
		mx=0;
		for(i=1;i<=n;i=j)
		{
			u=0;
			for(j=i;j<=n&&a[i].p==a[j].p;++j)
			{
				if(mx>a[j].p*(1-mid*a[j].r/sum))
					break;
				u=max(u,a[j].p*(1-mid*a[j].l/sum));
			}
			if(j<=n&&a[i].p==a[j].p)
				break;
			mx=max(mx,u);
		}
		if(i<=n)
			rt=mid;
		else
			lt=mid;
	}
	printf("%.12lf",lt);
	return 0;
}