#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 100010
#define DB double
#define inf 0x7ffffff

DB f[N][10];
int a[N],g[N][10];
int n,d;

int main()
{
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0,sizeof(f));
	for (int i=0;i<=9;i++)
		f[0][i]=-inf;
	f[0][1]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=9;j++)
		{
			f[i][j]=f[i-1][j];
			g[i][j]=j;
		}
		for (int j=0;j<=9;j++)
		{
			int k=(j*a[i])%10;
			if (f[i][k]<log(a[i])+f[i-1][j])
			{
				f[i][k]=f[i-1][j]+log((DB)a[i]);
				g[i][k]=j;
			}
		}
	}
	if (f[n][d]<0) 
	{
		printf("-1\n");
		return 0;
	}
	int s=0;
	int b[N];
	for (int i=n;i>=1;i--)
	{
		//printf("%d %d\n",d,g[i][d]);
		if ((g[i][d]*a[i])%10==d) 
		{
			b[++s]=a[i];
			d=g[i][d];
		}
	}
	if (s==0) 
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",s);
	for (int i=1;i<=s;i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}