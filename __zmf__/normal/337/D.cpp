//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9,INF=1e7;
int n,m,d,dp[N][2],g[N],cnt;
int to[N],nxt[N],head[N],ans;
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline void dfs1(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dfs1(to[i],u);
			if(dp[to[i]][0]+1>dp[u][0])
			{
				dp[u][1]=dp[u][0];dp[u][0]=dp[to[i]][0]+1;
			}
			else if(dp[to[i]][0]+1>dp[u][1])
			{
				dp[u][1]=dp[to[i]][0]+1;
			}
		}
}
inline void dfs2(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			if(dp[to[i]][0]+1==dp[u][0])g[to[i]]=max(dp[u][1]+1,g[u]+1);
			else g[to[i]]=max(dp[u][0]+1,g[u]+1);
			dfs2(to[i],u);
		}
}
int main()
{
	n=read(),m=read(),d=read();
	for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=g[i]=-INF;
	for(int i=1;i<=m;i++)
	{
		int x=read();dp[x][0]=dp[x][1]=0;
	}
	for(int i=1;i<n;i++)
	{
		int uu=read(),vv=read();addedge(uu,vv);addedge(vv,uu);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		if(g[i]<=d&&dp[i][0]<=d)
		{
		//	cout<<i<<" "<<g[i]<<" "<<dp[i][0]<<endl;
			ans++;
		}
	cout<<ans<<endl;
	return 0;
}