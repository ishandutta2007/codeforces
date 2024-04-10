#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)

ll n,q,ans=N,up[N];
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	for(auto u:e[x])
		if(u!=par)
			up[u]=min(u,up[x]),
			dfs(u,x);
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	ll t,x,lst=0;
	scanf("%d%d",&t,&x);x=(x%n)+1;
	up[x]=x;dfs(x);
	q--;
	while(q--)
	{
		scanf("%d%d",&t,&x);
		x=(x+lst)%n+1;
		if(t==1)ans=min(ans,up[x]);
		else printf("%d\n",min(up[x],ans)),lst=min(up[x],ans);	
	}
	return 0;
}