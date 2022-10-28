#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
const int N=200000+10;

struct Data
{
	double a,t;
}o[N],d[N],d2[N];

int n,T;
int l,l2;
double ans,x,y;

bool cmp(const Data& a,const Data& b)
{
	return a.t<b.t;
}

signed main()
{
	scanf("%lld%lld",&n,&T);
	int i,j;
	for(i=1;i<=n;++i)
		scanf("%lf",&o[i].a);
	for(i=1;i<=n;++i)
		scanf("%lf",&o[i].t);
	for(i=1;i<=n;++i)
	{
		o[i].t-=T;
		if(o[i].t==0)
			ans+=o[i].a;
		else if(o[i].t<0)
		{
			o[i].t*=-1;
			d[++l]=o[i];
		}
		else if(o[i].t>0)
			d2[++l2]=o[i];
	}
	sort(d+1,d+l+1,cmp);
	sort(d2+1,d2+l2+1,cmp);
	i=j=1;
	while(i<=l&&j<=l2)
	{
		x=d[i].a*d[i].t;
		y=d2[j].a*d2[j].t;
		if(x==y)
		{
			ans+=d[i].a+d2[j].a;
			++i;
			++j;
		}
		else if(x<y)
		{
			ans+=d[i].a+(x=x/d2[j].t);
			d2[j].a-=x;
			++i;
		}
		else
		{
			ans+=d2[j].a+(x=y/d[i].t);
			d[i].a-=x;
			++j;
		}
	}
	printf("%.10lf",ans);
	return 0;
}