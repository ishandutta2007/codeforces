#include<bits/stdc++.h>
using namespace std;
#define ll int
#define N (101*1000)
#define LG (20)

ll n,m,q,par[N][LG],dis[N];
vector <ll> e[N],c[N],dp[N][LG];

vector <ll> merge(vector <ll> b,vector <ll> b2)
{
	vector <ll> a;
	for(int i=0,j=0;a.size()<10 && (i<b.size() || j<b2.size());)
	{
		if(i>=b.size())a.push_back(b2[j++]);
		else if(j>=b2.size())a.push_back(b[i++]);
		else if(b[i]>b2[j])a.push_back(b2[j++]);
		else a.push_back(b[i++]);
	}
	return a;
}

void dfs(ll x,ll Par=0)
{
	dis[x]=dis[Par]+1;
	par[x][0]=Par;
	dp[x][0]=c[Par];
	for(int i=1;i<LG;i++)par[x][i]=par[par[x][i-1]][i-1],dp[x][i]=merge(dp[x][i-1],dp[par[x][i-1]][i-1]);
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=Par)
			dfs(e[x][i],x);			
}

ll iPar(ll x,ll num)
{
	for(int i=0;num;i++,num/=2)
		if(num%2)x=par[x][i];
	return x;	
}

ll cPar(ll x,ll y)
{
	if(dis[x]>dis[y])swap(x,y);
	y=iPar(y,dis[y]-dis[x]);
	for(int i=LG-1;i>=0;i--)
		if(par[x][i]!=par[y][i])
			x=par[x][i],y=par[y][i];
	return par[x][0];
}

vector <ll> iSolve(ll x,ll num)
{
	vector <ll> a;
	for(int i=0;num;i++,num/=2)
		if(num%2)
		{
			a=merge(a,dp[x][i]);
			x=par[x][i];
		}
	return a;	
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);	
	}	
	for(int i=0;i<m;i++)
	{
		ll v;
		scanf("%d",&v);
		c[v].push_back(i+1);
	}
	dfs(1);
	while(q--)
	{
		ll v,u,a;
		scanf("%d%d%d",&v,&u,&a);
		if(v==u)
		{
			printf("%d ",min(a,(ll)c[v].size()));
			for(int i=0;i<min(a,(ll)c[v].size());i++)printf("%d ",c[v][i]);
			printf("\n");
			continue;
		}
		if(dis[v]>dis[u])swap(u,v);
		if(iPar(u,dis[u]-dis[v])==v)
		{
			vector <ll> ans;
			ans=iSolve(u,dis[u]-dis[v]);
			ans=merge(ans,c[u]);
			printf("%d ",min(a,(ll)ans.size()));
			for(int i=0;i<min(a,(ll)ans.size());i++)printf("%d ",ans[i]);
			printf("\n");
			continue;
		}
		ll x=cPar(v,u);
		vector <ll> ans;
		ans=merge(c[u],merge(c[v],merge(c[x],merge(iSolve(u,dis[u]-dis[x]-1),iSolve(v,dis[v]-dis[x]-1)))));
		printf("%d ",min(a,(ll)ans.size()));
		for(int i=0;i<min(a,(ll)ans.size());i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}