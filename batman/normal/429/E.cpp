#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)
#define INF ((ll)2e9)

ll n,it[N],ans[N];
vector <ll> ex;
vector <pair<ll,ll> > e[N];
pair <ll,ll> a[N];

ll id(ll x){return lower_bound(ex.begin(),ex.end(),x)-ex.begin();}

void dfs(ll x)
{
	while(it[x]!=e[x].size())
	{
		ll u=e[x][it[x]].first,ind=e[x][it[x]].second;
		it[x]++;
		if(ans[ind])continue;
		if(x>u)ans[ind]=1;
		else ans[ind]=2;
		dfs(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;a[i].second++;
		ex.push_back(a[i].first);ex.push_back(a[i].second);
	}
	ex.push_back(INF);
	sort(ex.begin(),ex.end());ex.resize(unique(ex.begin(),ex.end())-ex.begin());
	for(int i=0;i<n;i++)
	{
		ll x=id(a[i].first),y=id(a[i].second);
		e[x].push_back({y,i});
		e[y].push_back({x,i});
	}
	for(int i=0,last=-1,p=n;i<ex.size();i++)
		if((ll)e[i].size()%2)
		{
			if(last==-1)last=i;
			else e[last].push_back({i,p}),e[i].push_back({last,p}),last=-1,p++;
		}
	for(int i=0;i<ex.size();i++)
		if(!it[i])
			dfs(i);
	for(int i=0;i<n;i++)cout<<ans[i]-1<<" ";
	return 0;
}