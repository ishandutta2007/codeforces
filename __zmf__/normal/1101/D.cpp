//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5;
int ans=0,n,cnt,a[N+9],b[N+9],dp[N+9],pre[N+9];
bool vis[N+9],used[N+9];
int head[N+9],nxt[2*N+9],to[2*N+9];
vector<int> tuu[N+9];
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline void dfs(int u,int f)
{
	used[u]=1;
	int mx=0,mxx=0;
	for(int i=head[u];i!=0;i=nxt[i])
		if(to[i]!=f&&b[to[i]])
		{
			dfs(to[i],u);
			if(mx<pre[to[i]])mxx=mx,mx=pre[to[i]];
			else if(mxx<pre[to[i]])mxx=pre[to[i]];
		}
	dp[u]=mx+mxx+1;pre[u]=mx+1;ans=max(ans,dp[u]);return ;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0)
			{
				if(j*j==a[i])tuu[j].push_back(i);
				else tuu[a[i]/j].push_back(i),tuu[j].push_back(i);
			}
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();addedge(x,y);addedge(y,x);
	}
	for(int i=2;i<=N;i++)
		if(!vis[i])
		{
			for(int j=0;j<tuu[i].size();j++)
			{
				int v=tuu[i][j];used[v]=0,b[v]=1;dp[v]=0,pre[v]=0;//cout<<v<<" ";
			}
			//cout<<endl;
			for(int j=0;j<tuu[i].size();j++)
			{
				int v=tuu[i][j];
				if(!used[v])dfs(v,-1);
			}
			for(int j=0;j<tuu[i].size();j++)
			{
				int v=tuu[i][j];b[v]=0,used[v]=0;
			}
		}
	cout<<ans<<endl;
	return 0;
}

/*
1. hpdf
2. xtw
3. smdd
4. ZMF
5. wz
6. asl
*/