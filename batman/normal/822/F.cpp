#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)1010)
#define INF ((ll)2e9)

ll n;
vector <pair<ll,ll> > e[N];

void dfs(ll x,ll par=0,ld num=0)
{
	ld step=(ld)2/((ld)e[x].size());
	if(x!=1)num+=step;
	if(num>=2)num-=2;
	for(auto u:e[x])
		if(u.first!=par)
		{
			cout<<"1 "<<u.second<<" ";
			if(num<1)cout<<x<<" "<<u.first<<" ",cout<<fixed<<setprecision(16)<<num<<"\n";
			else cout<<u.first<<" "<<x<<" ",cout<<fixed<<setprecision(16)<<num-(ld)1<<"\n";
			dfs(u.first,x,(num>1)?num-(ld)1:(ld)1+num);
			num+=step;
			if(num>=2)num-=2;
		}
}

int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back({u,i+1});
		e[u].push_back({v,i+1});
	}
	cout<<n-1<<"\n";
	dfs(1);
	return 0;
}