#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int n,a[15],g[15][2],a1;
LL f[15][15][2][2];

int work(int mx)
{
	g[a1+1][1]=1;
	for (int i=a1+1;i>mx+1;i--)
	{
		if (g[i][0]) g[i-1][0]+=g[i][0]*10;
		if (g[i][1])
		{
			g[i-1][1]+=g[i][1];
			g[i-1][0]+=g[i][1]*a[i-1];
		}
	}
	int ans=0,flag=0;
	for (int i=1;i<=mx;i++) if (a[i]!=9) {flag=1;break;}
	if (!flag) return g[mx+1][0]+g[mx+1][1];
	else return g[mx+1][0];
}

int main()
{
	scanf("%d",&n);
	int tmp=n;
	while (tmp) a[++a1]=tmp%10,tmp/=10;
	f[a1+1][0][1][1]=1;
	for (int i=a1+1;i>1;i--)
		for (int j=0;j<=a1;j++)
		{
			if (f[i][j][0][0])
			{
				LL w=f[i][j][0][0];
				for (int x=0;x<=9;x++)
					for (int y=0;y<=9;y++)
						if (x+y==9) f[i-1][j+1][0][0]+=w;
						else f[i-1][0][0][0]+=w;
			}
			if (f[i][j][0][1])
			{
				LL w=f[i][j][0][1];
				for (int x=0;x<=9;x++)
				{
					f[i-1][0][0][1]+=w;
					for (int y=0;y<x;y++)
						if (x+y==9) f[i-1][j+1][0][0]+=w;
						else f[i-1][0][0][0]+=w;
				}
			}
			if (f[i][j][1][0])
			{
				LL w=f[i][j][1][0];
				for (int x=0;x<=9;x++)
					if (x+a[i-1]==9) f[i-1][j+1][1][0]+=w;
					else f[i-1][0][1][0]+=w;
				for (int x=0;x<a[i-1];x++)
					for (int y=0;y<=9;y++)
						if (x+y==9) f[i-1][j+1][0][0]+=w;
						else f[i-1][0][0][0]+=w;
			}
			if (f[i][j][1][1])
			{
				LL w=f[i][j][1][1];
				f[i-1][0][1][1]+=w;
				for (int x=0;x<a[i-1];x++)
					if (x+a[i-1]==9) f[i-1][j+1][1][0]+=w;
					else f[i-1][0][1][0]+=w;
				for (int x=0;x<a[i-1];x++)
				{
					f[i-1][0][0][1]+=w;
					for (int y=0;y<x;y++)
						if (x+y==9) f[i-1][j+1][0][0]+=w;
						else f[i-1][0][0][0]+=w;
				}
			}
		}
	int mx=0;
	for (int i=a1;i>=0;i--) if (f[1][i][0][0]+f[1][i][1][0]>0) {mx=i;break;}
	if (!mx) {printf("%I64d",(LL)n*(n-1)/2);return 0;}
	printf("%I64d",f[1][mx][0][0]+f[1][mx][1][0]-(LL)work(mx));
	return 0;
}