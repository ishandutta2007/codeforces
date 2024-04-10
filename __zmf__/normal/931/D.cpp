//zhouakngyang txdy!
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
int n,fa[100009],dep[100009],cnt[100009],ans;
vector<int> G[100009];
inline void dfs(int u)
{
	cnt[dep[u]]++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dep[v]=dep[u]+1;
		dfs(v);
	}
	return ;
}
int main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		fa[i]=read();
		G[fa[i]].push_back(i);
	}
	dfs(1);
	for(int i=0;i<=n;i++)
		ans+=cnt[i]%2;
	cout<<ans<<endl;
	return 0;
}