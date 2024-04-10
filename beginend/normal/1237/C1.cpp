#include<bits/stdc++.h>

typedef long long LL;

const int N=2005;

int n,x[N],y[N],z[N];
bool vis[N];

LL dis(int i,int j)
{
	return (LL)(x[i]-x[j])*(x[i]-x[j])+(LL)(y[i]-y[j])*(y[i]-y[j])+(LL)(z[i]-z[j])*(z[i]-z[j]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		int pos=0;
		for (int j=i+1;j<=n;j++)
			if (!vis[j]&&(!pos||dis(i,j)<dis(i,pos))) pos=j;
		vis[i]=vis[pos]=1;
		printf("%d %d\n",i,pos);
	}
	return 0;
}