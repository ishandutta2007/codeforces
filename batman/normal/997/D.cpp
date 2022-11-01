#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)4010)
#define K ((int)76)
#define MOD ((int)998244353)

int n[2],k,ans[2][K],C[K][K];
int sz[N],dp[N][K],dp2[N][K];
bool dead[N];
vector <int> e[2][N],vec;

void pre_dfs(int x,bool p,int par=0)
{
	sz[x]=1;
	memset(dp[x],0,sizeof dp[x]);
	memset(dp2[x],0,sizeof dp2[x]);
	vec.push_back(x);
	for(auto u:e[p][x])
		if(!dead[u] && par!=u)
			pre_dfs(u,p,x),
			sz[x]+=sz[u];
}

int findroid(int x,bool p,int all,int par=0)
{
	for(auto u:e[p][x])
		if(!dead[u] && par!=u && sz[u]>all/2)
			return findroid(u,p,all,x);
	return x;
}

void solve(int x,bool p)
{
	pre_dfs(x,p);
	int v=findroid(x,p,sz[x]);
	dp[v][0]=1;
	for(int i=1;i<=k;i++)
		for(auto u:vec)
			for(auto q:e[p][u])
				if(!dead[q])
					dp[u][i]+=dp[q][i-1],dp[u][i]%=MOD;
	dead[v]=1;
	for(auto u:e[p][v])
		if(!dead[u])
			dp2[u][1]=1;
	for(int i=1;i<=k;i++)
		for(auto u:vec)
			if(u!=v)
				for(auto q:e[p][u])
					if(!dead[q])
						dp2[u][i]+=dp2[q][i-1],dp2[u][i]%=MOD;
	
	for(auto u:vec)
		if(u!=v)
			for(int i=0;i<=k;i++)
				for(int j=0;j<=i;j++)
					ans[p][i]+=1LL*dp[u][j]*dp2[u][i-j]%MOD,ans[p][i]%=MOD;
	for(int i=0;i<=k;i++)ans[p][i]+=dp[v][i],ans[p][i]%=MOD;
	vec.clear();
	for(auto u:e[p][v])
		if(!dead[u])
			solve(u,p);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n[0]>>n[1]>>k;
	for(int p=0;p<2;p++)
		for(int i=0;i<n[p]-1;i++)
		{
			int v,u;
			cin>>v>>u;
			e[p][v].push_back(u);
			e[p][u].push_back(v);
		}
	solve(1,0);
	memset(dead,0,sizeof dead);
	solve(1,1);
	for(int i=0;i<K;i++)C[i][i]=C[i][0]=1;
	for(int i=1;i<K;i++)for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	int res=0;
	for(int i=0;i<=k;i+=2)
		res+=1LL*(1LL*C[k][i]*ans[0][i]%MOD)*ans[1][k-i]%MOD,res%=MOD;
	cout<<res<<"\n";
	return 0;
}