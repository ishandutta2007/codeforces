#include<bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define MOD ((ll)1e9+7)

ll n,m,q,a[N],dp[N],ans[N];
vector <pair<ll,ll> > qu[N];
pair <ll,ll> lazy[4*N];

void update_lazy(ll id,ll x,ll y)
{
	if(lazy[id].first==-1){lazy[id]={x,y};return ;}
	if(x<=lazy[id].second)lazy[id]={min(x,lazy[id].first),y};
}

void shift(ll id)
{
	if(lazy[id].first==-1)return ;
	update_lazy(id*2,lazy[id].first,lazy[id].second);
	update_lazy(id*2+1,lazy[id].first,lazy[id].second);
	lazy[id]={-1,-1};
}

void update(ll ql,ll qr,ll x,ll y,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr){update_lazy(id,x,y);return ;}
	ll mid=(xl+xr)/2;
	shift(id);
	update(ql,qr,x,y,xl,mid,id*2);
	update(ql,qr,x,y,mid,xr,id*2+1);
}

void clean(ll q,ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1)
	{
		if(lazy[id].first==-1)return ;
		if(dp[xl]>=lazy[id].first)dp[xl]=lazy[id].second;
		lazy[id]={-1,-1};
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(id);
	if(q<mid)clean(q,xl,mid,id*2);
	else clean(q,mid,xr,id*2+1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<4*N;i++)lazy[i]={-1,-1};
	for(int i=0;i<n;i++)a[i]=-1;
	for(int i=0;i<m;i++)
	{
		ll l,r;
		cin>>l>>r;l--;r--;
		a[r]=l;
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		ll x,y;
		cin>>x>>y;x--;y--;
		qu[y].push_back({x,i});
	}
	for(int i=0;i<n;i++)
	{
		dp[i]=i;
		if(a[i]!=-1)update(0,a[i]+1,a[i],i);
		for(auto u:qu[i])
			clean(u.first),ans[u.second]=dp[u.first];
	}
	for(int i=0;i<q;i++)cout<<ans[i]+1<<"\n";
	return 0;
}