#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)201*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,a[N],cnt,num[N],dis=-1,ver,now;
bool mark[N];
vector <ll> e[N],e2[N];
vector <pair<ll,ll> > ed;

void dfs(ll x,ll clr)
{
	mark[x]=1;num[x]=cnt;
	for(auto u:e[x])
		if(!mark[u] && a[u]==clr)
			dfs(u,clr);
}

void dfs2(ll x)
{
	mark[x]=1;
	if(dis<now)dis=now,ver=x;
	for(auto u:e2[x])
		if(!mark[u])
			now++,dfs2(u),now--;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
		ed.push_back({u,v});
	}
	for(int i=1;i<=n;i++)
		if(a[i]==0 && !mark[i])
		{
			cnt++;
			dfs(i,0);
		}
	memset(mark,0,sizeof mark);
	for(int i=1;i<=n;i++)
		if(a[i]==1 && !mark[i])
		{
			cnt++;
			dfs(i,1);
		}
	for(auto u:ed)
		if(num[u.first]!=num[u.second])
			e2[num[u.first]].push_back(num[u.second]),
			e2[num[u.second]].push_back(num[u.first]);
	memset(mark,0,sizeof mark);
	dfs2(1);
	memset(mark,0,sizeof mark);
	dis=-1;
	dfs2(ver);
	cout<<(dis+1)/2;
	return 0;
}