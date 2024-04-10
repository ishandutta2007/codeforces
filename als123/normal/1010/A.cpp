#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const double eps=1e-7;
const int N=1005;
int n;
double m;
double a[N],b[N];
int main()
{
	scanf("%d%lf",&n,&m);
	for (int u=1;u<=n;u++)	scanf("%lf",&a[u]);
	for (int u=1;u<=n;u++) scanf("%lf",&b[u]);
	for (int u=1;u<=n;u++)
	{
		if (a[u]-1<eps) 	{printf("-1\n");return 0;}
		if (b[u]-1<eps) 	{printf("-1\n");return 0;}
	}
	double ans=-1;
	ans=m/(b[1]-1);
//	printf("%lf\n",ans);
	for (int u=n;u>=2;u--)
	{
		ans=ans+(m+ans)/(a[u]-1);
	//	printf("%lf\n",ans);
		ans=ans+(m+ans)/(b[u]-1);
	//	printf("%lf\n",ans);
	}
	ans=ans+(m+ans)/(a[1]-1);
	printf("%lf\n",ans);
	return 0;
}