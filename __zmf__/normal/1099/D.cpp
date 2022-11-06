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
const int N=1e5+9;
int n,fa[N],p[N],s[N],val[N],lth[N];
vector<int> G[N];
inline void dfs(int u,int f,int dep)
{
	if(dep%2==1)val[u]=s[u]-lth[fa[u]],lth[u]=lth[fa[u]]+val[u];
	else 
	{
		int res=1e9+7;
		for(int i=0;i<G[u].size();i++)res=min(res,s[G[u][i]]);
		if(res>1e9)return ;
		val[u]=res-s[fa[u]];lth[u]=lth[fa[u]]+val[u];
	}
	for(int i=0;i<G[u].size();i++)
		if(G[u][i]!=f)dfs(G[u][i],u,dep+1);
	return ;
}
signed main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		int u=read();G[u].push_back(i);fa[i]=u;
	}
	for(int i=1;i<=n;i++)s[i]=read();
	dfs(1,0,1);int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(val[i]<0)
		{
			puts("-1");return 0;
		}
		ans+=val[i];
	}
	cout<<ans<<endl;
	return 0;
}