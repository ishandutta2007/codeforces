#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=((n&1)?a:1ll),res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=201*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e18);

ll n,m,a[N],dp[N],seg[4*N],lazy[4*N];
vector <pair<ll,ll> > v[N];

void shift(ll id)
{
	ll l=id*2,r=l+1;
	seg[l]+=lazy[id];
	seg[r]+=lazy[id];
	lazy[l]+=lazy[id];
	lazy[r]+=lazy[id];
	lazy[id]=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll num)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id]+=num;
		lazy[id]+=num;
		return ;
	}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(id);
	update(ql,qr,xl,mid,l,num);
	update(ql,qr,mid,xr,r,num);
	seg[id]=max(seg[l],seg[r]);
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return -INF;
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	return max(query(ql,qr,xl,mid,l),query(ql,qr,mid,xr,r));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)
	{
		ll l,r,p;
		cin>>l>>r>>p;l--;r--;
		v[r].push_back({l,p});
	}
	for(int i=0;i<n;i++)
	{
		update(0,i+1,0,N,1,-a[i]);
		for(int j=0;j<v[i].size();j++)
			update(0,v[i][j].first+1,0,N,1,v[i][j].second);
		dp[i]=max((i)?dp[i-1]:0ll,query(0,i+1,0,N,1));
		update(i+2,i+3,0,N,1,dp[i]);
	}
	cout<<dp[n-1];
  	return 0;
}