#include<bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int w[100005],dep[100005],rr[100005],r1[100005],r2[100005];
long long t[100005];
void dfs(int x,int la)
{
	w[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dep[cu]=dep[x]+1;
		dfs(cu,x);
		w[x]+=w[cu];
	}
}
int main()
{
	int tr;
	cin>>tr;
	while(tr--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
			r1[i]=u,r2[i]=v;
		}
		dfs(1,0);
		int tot=0;
		for(int i=1;i<n;i++)
		{
			if(dep[r1[i]]>dep[r2[i]])swap(r1[i],r2[i]);
			t[++tot]=1ll*w[r2[i]]*(n-w[r2[i]]);
		}
		sort(t+1,t+tot+1,greater<long long>());
		int m;
		cin>>m;
		for(int i=1;i<=m;i++)scanf("%d",&rr[i]);
		sort(rr+1,rr+m+1,greater<int>());
		for(int i=m+1;i<n;i++)rr[i]=1;
		long long ans=0;
		if(m>=n)
		{
			long long jj=1;
			for(int i=1;i<=m-n+2;i++)jj=(1ll*jj*rr[i])%1000000007;
			ans=1ll*jj*t[1]%1000000007;
			for(int i=2;i<n;i++)ans=(ans+t[i]*rr[m-n+i+1])%1000000007;
		}else
		{
			for(int i=1;i<n;i++)ans=(ans+t[i]*rr[i])%1000000007;
		}
		cout<<ans<<endl;
	}
	return 0;
}