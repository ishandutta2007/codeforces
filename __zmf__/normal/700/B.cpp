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
int n,k,val[200009],son[200009],x,y;
int ans;
vector<int> G[200009];
inline void dfs(int u,int f)
{
	for(int i=0;i<G[u].size();i++)
	{
		int to=G[u][i];
		if(to==f)continue ;
		dfs(to,u);
		son[u]=son[u]+son[to];
	}
	ans=ans+min(son[u],k*2-son[u]);
	return ;
}
signed main()
{
	n=read();k=read();
	for(int i=1;i<=2*k;i++)x=read(),son[x]++;
	for(int i=1;i<n;i++)
	{
		x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,-1);
	cout<<ans<<endl;
	return 0;
}