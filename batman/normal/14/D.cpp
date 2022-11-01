#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (211)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,max_id,max_d,ans;
vector <ll> e[N];
deque <ll> q;
bool mark[N];

void dfs2(ll x,ll dis=0)
{
	mark[x]=1;
	if(dis>max_d)
		max_d=dis,max_id=x;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dfs2(e[x][i],dis+1);
	mark[x]=0;			
}

void dfs3(ll x,ll dis=0)
{
	mark[x]=1;
	if(dis>max_d)
		max_d=dis;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dfs3(e[x][i],dis+1);
}

void calc()
{
	for(int i=0;i<N;i++)mark[i]=0;
	for(int i=0;i<q.size();i++)mark[q[i]]=1;
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			max_d=0,max_id=i;
			dfs2(i);
			max_d=0;
			dfs3(max_id);
			ans=max(ans,(ll)(q.size()-1)*max_d);
		}
	
}

void dfs(ll x,ll par=0)
{
	q.push_back(x);
	calc();
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			dfs(e[x][i],x);
	q.pop_back();		
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
	for(int i=1;i<=n;i++)
		dfs(i);
	cout<<ans;		
	return 0;
}