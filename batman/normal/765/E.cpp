#include <bits/stdc++.h>
using namespace std; 
#define ll int
#define N ((ll)201*1000)

ll n,tmp[N];
pair <ll,ll> dp[N];
vector <ll> e[N];
bool dota[N];

void dfs(ll x,ll par=0)
{
//	cout<<x<<"||||| \n";
	bool mark=0;dota[x]=tmp[x]=0;
	set <ll> s;
	for(auto u:e[x])
	{
		if(u==par)continue;
		dfs(u,x);
//		cout<<u<<" "<<dp[u].first<<" "<<dp[u].second<<" "<<tmp[u]<<"\n";
		if(mark && dota[u])
		{
			cout<<-1;
			exit(0);
		}
		if(dota[u])dp[x]=dp[u],mark=1,tmp[x]=tmp[u]+1,dota[x]=1;
		else s.insert(dp[u].first+1);
	}
	if(s.size()>2 || (mark==1 && s.size()==2))
	{
		cout<<-1;
		exit(0);
	}
	if(mark)
	{
		if(s.size()==0)return ;
		if(*s.begin()+tmp[x]==dp[x].first)dp[x]={*s.begin(),tmp[x]+dp[x].second},tmp[x]=0;
		else if(*s.begin()+tmp[x]==dp[x].second)dp[x]={*s.begin(),tmp[x]+dp[x].first},tmp[x]=0;
		else{cout<<-1;exit(0);}
		return ;
	}
	if(s.size()==0){dp[x].first=0;return ;}
	if(s.size()==1){dp[x].first=*s.begin();return ;}
	dota[x]=1;dp[x]={*s.begin(),(*s.rbegin())};
}

ll f(ll x){while(x%2==0)x/=2;return x;}

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
	ll ans=N;
	for(int i=0;i<1;i++)
	{
		ll x=1;
		dfs(x);
		if(!dota[x]){ans=min(ans,f(dp[x].first));continue;}
		if(tmp[x]==0 || tmp[x]==dp[x].first || tmp[x]==dp[x].second){ans=min(ans,f(dp[x].first+dp[x].second));continue;}
	}
	if(ans==N)cout<<-1;
	else cout<<ans;
	return 0;
}