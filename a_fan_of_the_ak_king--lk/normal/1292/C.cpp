#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=100005,E=262144;
const long long inf=30000000000000000ll;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
int n,i,u,v,dfn[3005],lat[3005],siz[3005],head[3005],Next[6005],adj[6005],k,f[3005];
long long dp[3005][3005],ans;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void getsiz(int i,int fa)
{
	int j;
	dfn[i]=++k;
	siz[i]=1;
	f[i]=fa;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			getsiz(adj[j],i);
			siz[i]+=siz[adj[j]];
		}
	lat[i]=k;
}
int gx(int a,int fa,int b,int fb)
{
	if(dfn[a]<=dfn[fa]&&lat[a]>=lat[fa])
		return (n-siz[fa])*siz[b];
	else
		return siz[a]*siz[b];
}
long long dfs(int a,int fa,int b,int fb)
{
	if(dfn[a]>dfn[b])
	{
		swap(a,b);
		swap(fa,fb);
	}
	if(dp[a][b]!=-1)
		return dp[a][b];
	int i;
	dp[a][b]=0;
	for(i=head[b];i!=0;i=Next[i])
		if(adj[i]!=fb)
			dp[a][b]=max(dp[a][b],dfs(a,fa,adj[i],b)+gx(a,fa,adj[i],b));
	for(i=head[a];i!=0;i=Next[i])
		if(adj[i]!=fa)
			dp[a][b]=max(dp[a][b],dfs(adj[i],a,b,fb)+gx(adj[i],a,b,fb));
	return dp[a][b];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	k=0;
	getsiz(1,0);
	memset(dp,-1,sizeof(dp));
	for(i=2;i<=n;++i)
		ans=max(ans,dfs(f[i],i,i,f[i])+(n-siz[i])*siz[i]);
	cout<<ans;
}