#include<bits/stdc++.h>
using namespace std;

vector<int> G[202020];

int son[202020],cnt0=0,cnt1=0;
long long sum[202020];
void dfs1(int x,int fa,int p)
{
	if(p==0)
		cnt0++;
	else
		cnt1++;
	son[x]=1;
	for(int to:G[x])
	{
		if(to==fa)
			continue;
		dfs1(to,x,p^1);
		son[x]+=son[to];
		sum[x]+=sum[to]+son[to];
	}
}
int n;
void dfs2(int x,int fa)
{
	for(int to:G[x])
	{
		if(to==fa)
			continue;
		sum[to]+=sum[x]-sum[to]-son[to]+n-son[to];
		dfs2(to,x);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	
	dfs1(1,0,0);
	dfs2(1,0);
	/*
	for(int i=1;i<=n;i++)
		cout<<sum[i]<<" ";
	cout<<endl;
	cout<<cnt0<<" "<<cnt1<<endl;
	*/
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=sum[i];
	ans+=2ll*cnt0*cnt1;
	
	printf("%I64d\n",ans/4);
	return 0;
}