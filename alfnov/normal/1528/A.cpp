#include<bits/stdc++.h>
using namespace std;
long long f[2][100005];
int l[100005],r[100005];
vector<int>g[100005];
void dfs(int x,int la)
{
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs(cu,x);
		f[0][x]+=max(abs(l[x]-l[cu])+f[0][cu],abs(l[x]-r[cu])+f[1][cu]);
		f[1][x]+=max(abs(r[x]-l[cu])+f[0][cu],abs(r[x]-r[cu])+f[1][cu]);
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]),f[0][i]=f[1][i]=0;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		printf("%lld\n",max(f[0][1],f[1][1]));
	}
	return 0;
}