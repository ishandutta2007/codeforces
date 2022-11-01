#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((ll)201*1000)
#define MOD ((ll)1e9+7)

ll n,m,a[N],b[N];
pair <ll,ll> seg[4*N];

void update(ll ql,ll qr,ll val,ll time,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id]={val+xl-ql,time};
		return ;
	}
	ll mid=(xl+xr)/2;
	update(ql,qr,val,time,xl,mid,id*2);
	update(ql,qr,val,time,mid,xr,id*2+1);
}

pair <ll,ll> query(ll q,ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1)return seg[id];
	ll mid=(xl+xr)/2;
	pair <ll,ll> p,pp={seg[id].first+q-xl,seg[id].second};
	if(q<mid)p=query(q,xl,mid,id*2);
	else p=query(q,mid,xr,id*2+1);
	return (p.second>=pp.second)?p:pp;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i],a[i+n]=b[i],update(i,i+1,i+n,1);
	for(int i=2;i<=m+1;i++)
	{
		ll t,x,y,k;
		cin>>t;
		if(t==1)
		{
			cin>>x>>y>>k;x--;y--;
			update(y,y+k,x,i);
		}
		if(t==2)
		{
			cin>>x;x--;
			cout<<a[query(x).first]<<"\n";
		}
	}
	return 0;
}