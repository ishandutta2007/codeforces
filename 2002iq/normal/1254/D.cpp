#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
#define BU 1000
#define mod 998244353
int n,sz[150005],stt[150005],ent[150005],ct,dp[18][150005],dep[150005];
long long cur[150005],sum[150005];
vector<int> v[150005];
int pre(int node,int p)
{
	sz[node]=1;
	stt[node]=++ct;
	dp[0][node]=p;
	for (int i=1;i<18;i++)
	dp[i][node]=dp[i-1][dp[i-1][node]];
	dep[node]=dep[p]+1;
	for (int u:v[node])
	{
		if (u!=p)
		sz[node]+=pre(u,node);
	}
	ent[node]=ct;
	return sz[node];
}
void dfs(int node,int p,long long tmp)
{
	tmp+=sum[node]*(n-sz[node]);
	cur[node]+=tmp;
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node,tmp-sum[node]*sz[u]);
	}
}
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
int kth(int node,int k)
{
	for (int i=0;i<18;i++)
	{
		if (k&(1<<i))
		node=dp[i][node];
	}
	return node;
}
int main()
{
	int q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	pre(1,0);
	int inv=pow_log(n,mod-2);
	set<int> s;
	for (int i=0;i<q;i++)
	{
		if (i%BU==0)
		{
			long long tmp=0;
			for (int i=1;i<=n;i++)
			tmp+=sum[i]*sz[i];
			dfs(1,0,tmp);
			for (int i=1;i<=n;i++)
			sum[i]=0;
			s.clear();
		}
		int t,v,d;
		scanf("%d%d",&t,&v);
		if (t==1)
		{
			scanf("%d",&d);
			sum[v]+=d;
			s.insert(v);
		}
		else
		{
			long long ans=cur[v]%mod;
			for (int i:s)
			{
				int cnt=sz[i];
				if (stt[i]<=stt[v] && ent[v]<=ent[i] && i!=v)
				cnt=n-sz[kth(v,dep[v]-dep[i]-1)];
				if (i==v)
				cnt=n;
				ans=(ans+sum[i]*cnt)%mod;
			}
			printf("%I64d\n",(ans*inv)%mod);
		}
	}
}