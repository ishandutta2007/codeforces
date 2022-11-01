#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,a[N];
LL c[N];

void ins(int x,int y)
{
	while (x<=n) c[x]+=y,x+=x&(-x);
}

LL find(int x)
{
	LL ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	double ans=0;
	for (int i=1;i<=n;i++) ans+=(double)1.0*i*(i-1)/4*(n-i+1);
	for (int i=1;i<=n;i++) ans-=(double)1.0*(find(n)-find(a[i]))*(n-i+1),ins(a[i],i);
	ans/=(double)1.0*n*(n+1)/2;
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++) ans+=find(n)-find(a[i]),ins(a[i],1);
	printf("%.15lf\n",ans);
	return 0;
}