#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N=1005;

int n,m,a[N],b[N],f[N*2];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) f[i*2-1]=i;
	for (int i=2;i<=n;i++) f[i*2-2]=i;
	f[n*2]=1;
	double ans=0;
	for (int i=n*2;i>=1;i--)
	{
		double w=(i&1)?b[f[i]]:a[f[i]];
		if (fabs(1-w)>1e-12) ans=(ans+m/w)/(1-1/w);
		else {puts("-1");return 0;}
	}
	printf("%.10lf",ans);
	return 0;
}