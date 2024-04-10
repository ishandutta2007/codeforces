#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)201*1000)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,k,a[N],dp_down[N],dp_up[N],dp[N],ans;
vector <ll> e[N];
bool block[N],mark[N],block_down[N],block_up[N];

void dfs_down(ll x,ll par=0)
{
	block_down[x]=block[x];
	dp_down[x]=1;
	ll maxi=0;
	for(auto v:e[x])
		if(v!=par && !mark[v])
		{
			dfs_down(v,x);
			block_down[x]|=block_down[v];
			if(!block_down[v])dp_down[x]+=dp_down[v];
			else maxi=max(maxi,dp_down[v]);
		}
	dp_down[x]+=maxi;
}

void dfs_up(ll x,ll par=0)
{
	mark[x]=1;
	ll sum=0,block_num=block_up[x],id=0;
	ll id1=0,id2=0,maxi=0;
	if(!block_up[x])sum+=dp_up[x];
	else maxi=dp_up[x];
	for(auto v:e[x])
		if(v!=par && !mark[v])
		{
			if(block_down[v])
			{
				block_num++,id=v;
				if(dp_down[v]>dp_down[id1])id2=id1,id1=v;
				else if(dp_down[v]>dp_down[id2])id2=v;	
			}
			else sum+=dp_down[v];
		}
	for(auto v:e[x])
		if(v!=par && !mark[v])
		{
			block_up[v]=(block_num>=2 || (block_num==1 && id!=v));
			if(block_down[v])
			{
				if(v!=id1)dp_up[v]=sum+max(maxi,dp_down[id1]);
				else dp_up[v]=sum+max(maxi,dp_down[id2]);
			}
			else dp_up[v]=sum-dp_down[v]+max(maxi,dp_down[id1]);
			dp_up[v]++;
			dfs_up(v,x);
		}
	ans=max(ans,sum+max(maxi,dp_down[id1])+1);
}

bool check(ll x)
{
	for(int i=1;i<=n;i++)dp_down[i]=dp_up[i]=block_down[i]=block_up[i]=block[i]=mark[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)mark[i]=1;
		for(auto v:e[i])
			if(a[v]<x)
				block[i]=1;
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			ans=0;
			dfs_down(i);
			dfs_up(i);
			if(ans>=k)return 1;
		}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	ll l=0,r=(ll)1e7;
	while(l<r-1)
	{
		ll mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}