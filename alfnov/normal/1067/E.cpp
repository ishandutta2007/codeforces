#include<bits/stdc++.h>
#define mod 998244353
#define m2 499122177
using namespace std;
vector<int>g[500005];
int f[500005];
void dfs(int x,int la)
{
	int aa=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs(cu,x);
		aa=1ll*aa*((m2+1ll*m2*f[cu])%mod)%mod;
	}
	f[x]=(1-aa)%mod;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+2ll*f[i])%mod;
	for(int i=1;i<n;i++)ans=2ll*ans%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}