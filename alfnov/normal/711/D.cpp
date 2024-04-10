#include<bits/stdc++.h>
using namespace std;
int n,vist[200005],s[200005],pp[200005],tot=0,q[200005];
vector<int>g[200005];
bool dfs2(int x,int la,int col)
{
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		if(vist[cu]==col)
		{
			vist[x]=col;
			return true;
		}
		bool tt=dfs2(cu,x,col);
		if(tt)
		{
			vist[x]=col;
			return true;
		}
	}
	return false;
}
void dfs(int x,int la,int col)
{
	if(vist[x])
	{
		vist[x]=col;
		dfs2(x,0,col);
		return;
	}
	vist[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs(cu,x,col);
	}
}
int powdv(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%1000000007;
		y>>=1;
		x=1ll*x*x%1000000007;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		g[i].push_back(x);
		g[x].push_back(i);
	}
	for(int i=1;i<=n;i++)if(!vist[i])
	{
		pp[i+1]=1;
		dfs(i,0,i+1);
	}
	for(int i=1;i<=n;i++)s[vist[i]]++;
	for(int i=2;i<=n+1;i++)if(pp[i]&&s[i]==1)s[i]=2;
	for(int i=2;i<=n+1;i++)if(s[i])q[++tot]=s[i];
	int ans=1,al=n;
	for(int i=1;i<=tot;i++)
	{
		al-=q[i];
		ans=1ll*ans*(powdv(2,q[i])-2)%1000000007;
	}
	ans=1ll*ans*powdv(2,al)%1000000007;
	cout<<ans;
	return 0;
}