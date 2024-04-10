#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,ans,x,y,a[2005][2005],l,r,q[2005],f[2005],g[2005];
int main()
{
	cin>>n>>m>>s>>t;
	for (int i=1;i<=m;++i)
	{
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	memset(f,-1,sizeof(f));
	q[1]=s;
	f[s]=0;
	l=0;
	r=1;
	while (l!=r)
	{
		int now=q[++l];
		for (int i=1;i<=n;++i)
			if (f[i]<0&&a[now][i])
			{
				f[i]=f[now]+1;
				q[++r]=i;
			}
	}
	q[1]=t;
	memset(g,-1,sizeof(g));
	g[t]=0;
	l=0;
	r=1;
	while (l!=r)
	{
		int now=q[++l];
		for (int i=1;i<=n;++i)
			if (g[i]<0&&a[now][i])
			{
				g[i]=g[now]+1;
				q[++r]=i;
			}
	}
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			if (!a[i][j])
			{
				if (f[i]+g[j]+1>=f[t]&&f[j]+g[i]+1>=f[t])
					++ans;
			}
	cout<<ans;
	return 0;
}