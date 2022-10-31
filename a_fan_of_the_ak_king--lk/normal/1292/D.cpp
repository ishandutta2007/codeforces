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
int n,i,u,v,a,p[N],f[N],mx[N],s[N],k,fa[N],faf[N],ind[N],sum,siz[N],j;
int head[N],Next[N*2],adj[N*2],op;
long long dp[N],ans=inf,leng[N*2];
void Push(int u,int v,int w)
{
	Next[++op]=head[u];
	head[u]=op;
	adj[op]=v;
	leng[op]=w;
}
void getsiz(int i,int fa)
{
	int j;
	siz[i]=p[i];
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			getsiz(adj[j],i);
			siz[i]+=siz[adj[j]];
			dp[i]+=1ll*siz[adj[j]]*leng[j]+dp[adj[j]];
		}
}
void dfs(int i,int fa)
{
	int j;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			dp[adj[j]]=dp[i]+1ll*(n-2*siz[adj[j]])*leng[j];
			dfs(adj[j],i);
		}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	f[1]=1;
	for(i=2;i<=5000;++i)
		if(!f[i])
			for(j=i;j<=5000;j+=i)
				f[j]=i;
	for(i=2;i<=5000;++i)
		if(f[i]==i)
			for(j=i;j<=5000;j+=i)
				mx[j]=max(mx[j],i);
	k=1;
	ind[1]=1;
	for(i=2;i<=5000;++i)
	{
		++k;
		int leng=0;
		for(j=mx[i];j<=5000;++j)
			leng+=s[j];
		int tmp=leng;
		leng=sum-leng;
		if(leng==0)
			fa[k]=ind[i-1];
		else
		{
		for(j=ind[i-1];leng>faf[j];j=fa[j])
			leng-=faf[j];
		if(leng==faf[j])
			fa[k]=fa[j];
		else
		{
			fa[k]=fa[j];
			fa[j]=k;
			faf[k]=faf[j]-leng;
			faf[j]=leng;
			++k;
			fa[k]=k-1;
		}
		}
		for(j=i;j!=1;j/=f[j])
		{
			assert(f[j]);
			++s[f[j]];
			++sum;
		}
		faf[k]=sum-tmp;
		ind[i]=k;
	}
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		++p[ind[a]];
	}
	for(i=2;i<=k;++i)
	{
		Push(fa[i],i,faf[i]);
		//cout<<fa[i]<<' '<<faf[i]<<endl;
	}
	getsiz(1,0);
	dfs(1,0);
	for(i=1;i<=k;++i)
		ans=min(ans,dp[i]);
	cout<<ans;
}