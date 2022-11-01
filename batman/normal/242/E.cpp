#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll MOD=((ll)1e9+7);
const ll N =101*1000;
const ll K=25;

ll n,m,a[N],seg[K][4*N],lazy[K][4*N];

void build(ll xl,ll xr,ll id,ll bit)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg[bit][id]=((a[xl]&(1<<bit))!=0);return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	build(xl,mid,l,bit);
	build(mid,xr,r,bit);
	seg[bit][id]=seg[bit][l]+seg[bit][r];
}

void shift(ll xl,ll xr,ll id,ll bit)
{
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	if(lazy[bit][id])
		seg[bit][l]=mid-xl-seg[bit][l],
		seg[bit][r]=xr-mid-seg[bit][r],
		lazy[bit][l]^=lazy[bit][id],
		lazy[bit][r]^=lazy[bit][id],
		lazy[bit][id]=0;
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id,ll bit)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[bit][id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(xl,xr,id,bit);
	return query(ql,qr,xl,mid,l,bit)+
			query(ql,qr,mid,xr,r,bit);
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll bit)
{	
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr){lazy[bit][id]=!lazy[bit][id];seg[bit][id]=xr-xl-seg[bit][id];return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(xl,xr,id,bit);
	update(ql,qr,xl,mid,l,bit);
	update(ql,qr,mid,xr,r,bit);
	seg[bit][id]=seg[bit][l]+seg[bit][r];
}


int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<K;i++)build(0,N,1,i);
	cin>>m; 
	while(m--)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll l,r;
			cin>>l>>r;
			long long ans=0;
			for(int i=0;i<K;i++)
				ans+=((long long)(1<<i))*query(l-1,r,0,N,1,i);
			cout<<ans<<"\n";
		}
		if(t==2)
		{
			ll l,r,x;
			cin>>l>>r>>x;
			for(int i=0;i<K;i++,x/=2)
				if(x%2)
					update(l-1,r,0,N,1,i);
		}
	}
	
	return 0;
}