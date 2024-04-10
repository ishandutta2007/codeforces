#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 101*1000
ll n,dp[N];
vector <ll> e[N];
bool mark[N],mark2[N];
vector <ll> ans;
void dfs(ll x)
{
	dp[x]=mark2[x];
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			mark[e[x][i]]=1,dfs(e[x][i]),dp[x]+=dp[e[x][i]];
	if(dp[x]==1 && mark2[x])
		ans.push_back(x);		
}


int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		ll u,v,t;
		cin>>u>>v>>t;
		e[u].push_back(v);
		e[v].push_back(u);
		if(t==2)
			mark2[u]=mark2[v]=1;
	}
	mark[1]=1;
	dfs(1);
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
    return 0;
}