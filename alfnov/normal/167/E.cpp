#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int mod;
int powdv(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int niyuan(int x)
{
	return powdv(x,mod-2);
}
int f[605][605],g1[605],g2[605],deg[605],ged[605],a[605][605];
int N,vist[605];
vector<int>g[605];
void dfs(int x)
{
	vist[x]=1;
	if(!ged[x])f[x][x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(!vist[cu])dfs(cu);
		for(int j=1;j<=N;j++)f[x][j]=(f[x][j]+f[cu][j])%mod;
	}
}
int main()
{
	int m,t1=0,t2=0;
	cin>>N>>m>>mod;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		deg[v]++,ged[u]++;
	}
	for(int i=1;i<=N;i++)if(!deg[i])dfs(i);
	for(int i=1;i<=N;i++)
	{
		if(!deg[i])g1[++t1]=i;
		if(!ged[i])g2[++t2]=i;
	}
	for(int i=1;i<=t1;i++)for(int j=1;j<=t2;j++)a[i][j]=f[g1[i]][g2[j]];
	int n=t1,r=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][i])break;
			if(!a[j][i])continue;
			r=-r;
			for(int k=1;k<=n;k++)swap(a[i][k],a[j][k]);
			break;
		}
		if(!a[i][i])
		{
			r=0;
			break;
		}
		for(int j=i+1;j<=n;j++)
		{
			int dd=-1ll*a[j][i]*niyuan(a[i][i])%mod;
			for(int k=i;k<=n;k++)a[j][k]=(a[j][k]+1ll*dd*a[i][k])%mod;
		}
	}
	for(int i=1;i<=n;i++)r=1ll*r*a[i][i]%mod;
	r=(r+mod)%mod;
	cout<<r<<endl;
	return 0;
}