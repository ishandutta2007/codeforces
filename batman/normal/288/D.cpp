#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)80*1000+100)

int n,sz[N];
vector <int> e[N];
ll dp[N],dp2[N],ex;

void dfs(int x,int par=0)
{
	ll sum_sz=0,sum2=0;sz[x]=1;
	for(auto u:e[x])
	{
		if(u==par)continue;
		dfs(u,x);
		ex=sz[u];
		sz[x]+=ex;
		dp[x]+=dp[u]+ex*(ex-1)/2*sum_sz;
		sum2+=ex*(sz[x]-ex-1);
		sum_sz+=ex*(ex-1)/2;
	}
	for(auto u:e[x])
	{
		if(u==par)continue;
		ex=sz[u];
		dp2[x]+=dp2[u]+ex*(sum_sz-ex*(ex-1)/2);
		dp[x]+=dp2[u]*(sz[x]-ex-1);
		dp[x]+=ex*(ex-1)/2*(sum2-ex*(sz[x]-ex-1));
	}
	dp[x]+=dp2[x];
	dp2[x]+=sum_sz;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int v,u;
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1);
	printf("%lld",2*dp[1]);
	return 0;
}