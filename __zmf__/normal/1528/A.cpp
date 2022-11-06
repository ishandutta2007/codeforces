//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e5+9;
int taxi,dp[N][2],n,l[N],r[N],uu,vv; 
vector<int> G[N];
inline void dfs(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
		if(G[u][i]!=fa)
		{
			int v=G[u][i];
			dfs(v,u);
			dp[u][0]+=max(dp[v][0]+abs(l[v]-l[u]),dp[v][1]+abs(r[v]-l[u]));
			dp[u][1]+=max(dp[v][0]+abs(l[v]-r[u]),dp[v][1]+abs(r[v]-r[u]));
		}
	return ;
}
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		for(int i=1;i<=n;i++)l[i]=read(),r[i]=read(),dp[i][0]=dp[i][1]=0;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++)
		{
			uu=read(),vv=read();G[uu].push_back(vv);G[vv].push_back(uu);
		}
		dfs(1,-1);
		cout<<max(dp[1][0],dp[1][1])<<endl;
	}
	return 0;
}