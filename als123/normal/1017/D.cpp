#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=15;
int n,m,q;
int cnt[1<<12];
char ss[N];
int read ()
{
	scanf("%s",ss);
	int now=0,bin=1;
	for (int u=0;u<n;u++)
		if (ss[u]=='0')
			now|=(1<<u);
	return now;
}
int w[N];
int f[15][1<<12][105];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int u=1;u<=n;u++) scanf("%d",&w[u]);
	for (int u=1;u<=m;u++) 
	{
		int t=read();
		cnt[t]++;
	}
	for (int u=0;u<(1<<n);u++)
		for (int i=0;i<=100;i++)
			f[n+1][u][i]=cnt[u];
	for (int u=n;u>=1;u--)
		for (int i=0;i<(1<<n);i++)
			for (int j=0;j<=100;j++)
			{
				f[u][i][j]=f[u+1][i^(1<<(u-1))][j];
				if (j>=w[u])
					f[u][i][j]=f[u][i][j]+f[u+1][i][j-w[u]];
				//printf("YES:%d %d %d %d %d\n",u,i,j,f[u][i][j],i^(1<<(u-1)));
			}
	while (q--)
	{
		int x=read(),k;
		//printf("NO:%d\n",x);
		scanf("%d",&k);
		printf("%d\n",f[1][x][k]);
	}
	return 0;
}