#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)301*1000)

ll n,a[N],lazy[4*N];
pair <ll,ll> seg[4*N];
stack <pair<ll,ll> > maxi,mini;
long long ans;

void merge(ll id)
{
	seg[id].first=max(seg[id*2].first,seg[id*2+1].first);
	seg[id].second=0;
	if(seg[id*2].first==seg[id].first)seg[id].second+=seg[id*2].second;
	if(seg[id*2+1].first==seg[id].first)seg[id].second+=seg[id*2+1].second;
}

void build(ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1)
	{
		seg[id].second=1;
		return ;
	}
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	merge(id);
}

void update(ll ql,ll qr,ll val,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		lazy[id]+=val;
		seg[id].first+=val;
		return ;
	}
	ll mid=(xl+xr)/2;
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	seg[id*2].first+=lazy[id];
	seg[id*2+1].first+=lazy[id];
	lazy[id]=0;
	update(ql,qr,val,xl,mid,id*2);
	update(ql,qr,val,mid,xr,id*2+1);
	merge(id);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;x--;y--;
		a[x]=y;
	}
	build();
	for(int i=0;i<n;i++)update(i,i+1,-i);
	maxi.push({n,-1});
	mini.push({-1,-1});
	for(int i=0;i<n;i++)
	{
		while(maxi.top().first<a[i])
		{
			ll x=maxi.top().first,id=maxi.top().second;maxi.pop();
			update(maxi.top().second+1,id+1,x);
		}
		update(maxi.top().second+1,i+1,-a[i]);maxi.push({a[i],i});
		while(mini.top().first>a[i])
		{
			ll x=mini.top().first,id=mini.top().second;mini.pop();
			update(mini.top().second+1,id+1,-x);
		}
		update(mini.top().second+1,i+1,a[i]);mini.push({a[i],i});
		if(i)update(0,n,1);
		if(seg[1].first==0)ans+=seg[1].second;
	}
	cout<<ans;
	return 0;
}