#include<bits/stdc++.h>
using namespace std;
int p[100005],h[100005],a[100005],b[100005],sz[100005],flag;
vector<int>g[100005];
void dfs(int x,int la)
{
	sz[x]=p[x];
	int siga=0,sigb=0;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs(cu,x);
		siga+=a[cu],sigb+=b[cu];
		sz[x]+=sz[cu];
	}
	if((sz[x]+h[x])&1)flag=0;
	a[x]=(sz[x]+h[x])/2,b[x]=(sz[x]-h[x])/2;
	if(a[x]<0||b[x]<0)flag=0;
	if(a[x]<siga)flag=0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)scanf("%d",&h[i]);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		flag=1;
		dfs(1,0);
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}