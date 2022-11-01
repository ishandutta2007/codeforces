#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n;
vector <ll> e[N];
pair <ll,ll> ans[N];

void dfs(ll x,ll par,ll dir,ll step)
{
	ans[x]=ans[par];
	if(dir==0)ans[x].first+=step;
	if(dir==1)ans[x].second-=step;
	if(dir==2)ans[x].second+=step;
	if(dir==3)ans[x].first-=step;
	for(int i=0,new_dir=0;i<e[x].size();i++)
	{
		if(new_dir==3-dir)new_dir++;
		if(e[x][i]==par)continue;
		dfs(e[x][i],x,new_dir,step/2);
		new_dir++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)if((ll)e[i].size()>4)return cout<<"NO",0;
	for(int i=0;i<e[1].size();i++)
		dfs(e[1][i],1,i,(1LL<<33));
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
}