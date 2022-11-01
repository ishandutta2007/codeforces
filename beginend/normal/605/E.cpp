#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1005;

int n,p[N][N];
double f[N],g[N];
bool vis[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&p[i][j]);
	for (int i=1;i<n;i++) f[i]=g[i]=1;
	for (int i=1;i<=n;i++)
	{
		double mn=1e9;int pos=0;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&g[j]<1&&f[j]/(1-g[j])<mn) mn=f[j]/(1-g[j]),pos=j;
		if (!pos) break;
		vis[pos]=1;
		f[pos]/=(1-g[pos]);
		for (int j=1;j<=n;j++)
			if (!vis[j])
			{
				f[j]+=g[j]*f[pos]*((double)p[j][pos]/100);
				g[j]*=(double)(100-p[j][pos])/100;
			}
	}
	printf("%.10lf",f[1]);
	return 0;
}