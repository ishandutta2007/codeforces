#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
#define ll long long
#define N ((int)501*1000)
#define K ((int)19)

int n,k,m;
ll ans;
vector <pair<int,pair<int,int> > > ed,edx;
vector <pair<int,int> > e[N];
int par[K][N],dis[N];

int pari[N];
int root(int x){if(pari[x]<0)return x;return pari[x]=root(pari[x]);}

void pre_dfs(int x)
{
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
		if(u.first!=par[0][x])
			par[0][u.first]=x,
			dis[u.first]=dis[x]+1,
			pre_dfs(u.first);
}

int iPar(int x,int num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

int lca(int x,int y)
{
	if(dis[x]<dis[y])swap(x,y);
	x=iPar(x,dis[x]-dis[y]);
	if(x==y)return x;
	for(int i=K-1;i>=0;i--)
		if(par[i][x]!=par[i][y])
			x=par[i][x],y=par[i][y];
	return par[0][x];
}

priority_queue <pair<int,int> > q[N];
vector <pair<int,int> > vec[N];

void dfs(int x)
{
	for(auto u:vec[x])
		q[x].push({-u.first,u.second});
	for(auto u:e[x])
	{
		if(u.first==par[0][x])continue;
		dfs(u.first);
		if(u.second==0)
		{
			while(q[u.first].size() && q[u.first].top().second>=dis[u.first])q[u.first].pop();
			if(!q[u.first].size())
			{
				printf("-1\n");
				exit(0);
			}
			ans+=-q[u.first].top().first;
		}
		if(q[u.first].size()>q[x].size())q[u.first].swap(q[x]);
		while(q[u.first].size())
		{
			if(q[u.first].top().second<dis[x])q[x].push(q[u.first].top());
			q[u.first].pop();
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<k;i++)
	{
		int v,u;
		scanf("%d%d",&v,&u);
		ed.push_back({0,{v,u}});
	}
	for(int i=0;i<m;i++)
	{
		int v,u,w;
		scanf("%d%d%d",&v,&u,&w);
		ed.push_back({w,{v,u}});
	}
	sort(ed.begin(),ed.end());
	for(int i=1;i<=n;i++)pari[i]=-1;
	for(auto x:ed)
	{
		int v=x.second.first,u=x.second.second;
		if(root(u)!=root(v))pari[root(v)]=root(u),e[v].push_back({u,x.first}),e[u].push_back({v,x.first});
		else edx.push_back(x);
	}
	ed.clear();
	pre_dfs(1);
	for(auto x:edx)
	{
		int v=x.second.first,u=x.second.second,w=x.first;
		int p=lca(v,u);
		if(v!=p)vec[v].push_back({w,dis[p]});
		if(u!=p)vec[u].push_back({w,dis[p]});
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}