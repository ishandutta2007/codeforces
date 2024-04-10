#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)

ll n,m,k,now;
vector <ll> e[N],res[N];
bool mark[N];

void add(ll x)
{
	if(res[now].size()==(2*n+k-1)/k)now++;
	res[now].push_back(x);
}

void dfs(ll x)
{
	add(x);
	mark[x]=1;
	for(auto u:e[x])
		if(!mark[u])
		{
			dfs(u);
			if(x==1 && u==e[x][(ll)e[x].size()-1])continue;
			add(x);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1);
	for(int i=0;i<k;i++)
	{
		if(!res[i].size())res[i].push_back(1);
		cout<<res[i].size()<<" ";
		for(auto u:res[i])cout<<u<<" ";
		cout<<"\n";
	}
	return 0;
}