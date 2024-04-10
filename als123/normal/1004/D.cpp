#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000005;
int t;
int a[N];
int cnt[N];
int main()
{
	scanf("%d",&t);
	for (int u=1;u<=t;u++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	int x=0,y;
	for (int u=1;u<=t;u++) 
		if (a[u]!=(u*4))
			{x=u;break;}
	//printf("%d %d %d\n",x,a[x],x*4);
	int b;
	for (int u=0;u<=t;u++)
		if (a[u]!=0)
			b=u;
	for (int n=1;n*n<=t;n++)
		if (t%n==0)
		{
			int m=t/n;
			int y=n+m-x-b;
			if (abs(n-x)+abs(m-y)!=b) continue;
			for (int u=0;u<=n+m;u++) cnt[u]=0;
			for (int u=1;u<=n;u++)
				for (int i=1;i<=m;i++)
					cnt[abs(u-x)+abs(i-y)]++;
			bool tf=false;
			for (int u=0;u<=n+m;u++)
				if (cnt[u]!=a[u])
					{tf=true;break;}
			if (tf==false)
			{
				printf("%d %d\n%d %d\n",n,m,x,y);
				return 0;
			}
		}
	for (int m=1;m*m<=t;m++)
		if (t%m==0)
		{
			int n=t/m;
			int y=n+m-x-b;
			if (abs(n-x)+abs(m-y)!=b) continue;
			for (int u=0;u<=n+m;u++) cnt[u]=0;
			for (int u=1;u<=n;u++)
				for (int i=1;i<=m;i++)
					cnt[abs(u-x)+abs(i-y)]++;
			bool tf=false;
			for (int u=0;u<=n+m;u++)
				if (cnt[u]!=a[u])
					{tf=true;break;}
			if (tf==false)
			{
				printf("%d %d\n%d %d\n",n,m,x,y);
				return 0;
			}
		}
	printf("-1");
	return 0;
}