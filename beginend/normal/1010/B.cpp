#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,m,f[105];

int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)
	{
		printf("%d\n",1);
		fflush(stdout);
		int x;scanf("%d",&x);
		if (x==0) return 0;
		if (x==1) f[i]=1;
		else f[i]=0;
	}
	int l=1,r=m,s=0;
	while (l<=r)
	{
		s=s%n+1;
		int mid=(l+r)/2;
		printf("%d\n",mid);
		fflush(stdout);
		int x;scanf("%d",&x);
		if (x==0) return 0;
		if (!f[s]) x*=-1;
		if (x==1) l=mid+1;
		else r=mid-1;
	}
	return 0;
}