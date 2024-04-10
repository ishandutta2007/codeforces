#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int a[35];
int n,m;
int main()
{
	scanf("%d%d",&m,&n);
	for (int u=1;u<=n;u++)
	{
		printf("%d\n",1);
		fflush(stdout);
		scanf("%d",&a[u]);
		if (a[u]==0)	return 0;
	}
	int l=1,r=m;
	int u=1;
	while (l<=r)
	{
		int mid=(l+r)>>1,x;
		printf("%d\n",mid);
		fflush(stdout);
		scanf("%d",&x);
		if (x==0) return 0;
		x=x*a[u];
		if (x==1) l=mid+1;
		else r=mid-1;
		u++;
		if (u>n) u=1;
	}
	return 0;
}