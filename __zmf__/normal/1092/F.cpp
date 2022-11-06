//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9,M=4e5+9;
int n,a[200009],dp[200009],val[200009],dep[200009],sum;
int to[M],nxt[M],head[N],cnt;
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
	to[++cnt]=u,nxt[cnt]=head[v],head[v]=cnt;
}
inline void dfs(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dep[to[i]]=dep[u]+1;
			dfs(to[i],u);
			val[u]+=val[to[i]];
		}
	return ;
}
inline void dfs1(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dp[to[i]]=dp[u]+sum-2*val[to[i]];
			dfs1(to[i],u);
		}
	return ;
}
signed main()
{
	int ans=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),val[i]=a[i],sum+=a[i];
	for(int i=1;i<n;i++)
	{
		int uu=read(),vv=read();
		addedge(uu,vv);
	}
	dfs(1,0);
//	for(int i=1;i<=n;i++)cout<<dep[i]<<endl;
	for(int i=1;i<=n;i++)dp[1]+=dep[i]*a[i];
//	cout<<dp[1]<<endl;
	dfs1(1,0);
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
//	cout<<dp[3]<<endl;
	cout<<ans<<endl;
	return 0;
}