#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> e[2005];
int dp[2005][2005],sz[2005],s[2005][2005];
int mod;
int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1) rtn=rtn*x%mod;
		x=x*x%mod,y>>=1;
	}
	return rtn;
}
int inv(int x)
{
	return ksm(x,mod-2);
}
int pl[2005][2005],pr[2005][2005];
void dfs(int u,int fa)
{
	for(auto v:e[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
	for(int i=1;i<=2000;i++) pl[0][i]=1,pr[e[u].size()][i]=1;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa)
		{
			for(int j=1;j<=2000;j++)
				pl[i+1][j]=(pl[i][j])%mod;
			continue;
		}
		for(int j=1;j<=2000;j++)
			pl[i+1][j]=(pl[i][j]*s[v][j])%mod;
	}
	for(int i=e[u].size()-1;i>=0;i--)
	{
		int v=e[u][i];
		if(v==fa)
		{
			for(int j=1;j<=2000;j++)
				pr[i][j]=pr[i+1][j]%mod;
			continue;
		}
		for(int j=1;j<=2000;j++)
			pr[i][j]=(pr[i+1][j]*s[v][j])%mod;
	}
	int p[2005]={};
	for(int i=1;i<=2000;i++) p[i]=1;
	for(auto v:e[u])
	{
		if(v==fa) continue;
		for(int j=1;j<=2000;j++)
			p[j]=(p[j]*s[v][j])%mod;
	}
	for(int i=1;i<=2000;i++)
	{
		dp[u][i]=pl[e[u].size()][i];
	}
	int CNT=0;
	if(u!=1) for(auto v:e[u])
	{
		++CNT;
		if(v==fa) continue;
		int S[2005]={};
		for(int j=1;j<=2000;j++)
		{
			//int x=p[j]*inv(s[v][j])%mod;
			int x=pl[CNT-1][j]*pr[CNT][j]%mod;
		/*	if(x!=p[j]*inv(s[v][j])%mod)
			{
			//	cout << x << " " << CNT-1 << " " << CNT+1 << "**\n";
				exit(u*1000+v+j*100000);
			}*/
			S[j+1]+=x;
		}
		for(int j=1;j<=2000;j++)
			S[j]=(S[j-1]+S[j])%mod,dp[u][j]=(dp[u][j]+S[j]*dp[v][j])%mod;
	}
	for(int i=1;i<=2000;i++)
		s[u][i]=(s[u][i-1]+dp[u][i])%mod;
}
int C[2005][2005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> mod;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			dp[1][i]=(dp[1][i]-dp[1][j]*C[i][j])%mod;
	}
	for(int i=1;i<n;i++)
		cout << (dp[1][i]%mod+mod)%mod << " ";
	return 0;
}
/*

2 9982444353
1 2
*/