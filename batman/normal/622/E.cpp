#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (501*1000)
#define K (1001*1000)

ll n,d,ans;
vector <ll> e[N];
deque <ll> q;

void dfs(ll x,ll par)
{
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			d++,dfs(e[x][i],x),d--;
	if(e[x].size()==1)q.push_back(d);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=0;i<e[1].size();i++)
	{
		dfs(e[1][i],1);
		sort(q.begin(),q.end());
		ll x=-1;
		while(q.size())
		{
			if(x<q.front())x=q.front();
			else x++;
			q.pop_front();
		}
		ans=max(ans,x);
	}
	cout<<ans+1;
	return 0;
}