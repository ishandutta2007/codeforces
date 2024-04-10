#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

int n,strt,fnsh,sz[N];
vector <int> e[N];
bool mark[N];

void dfs(int x,int par=0)
{
	if(x==fnsh)mark[x]=1;
	sz[x]=1;
	for(auto u:e[x])
		if(u!=par)
			dfs(u,x),
			sz[x]+=sz[u],
			mark[x]|=mark[u];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>strt>>fnsh;
	for(int i=0;i<n-1;i++)
	{
		int v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(strt);
	for(auto u:e[strt])
		if(mark[u])
			return cout<<1LL*n*(n-1)-1LL*(n-sz[u])*sz[fnsh]<<"\n",0;
	return 0;
}