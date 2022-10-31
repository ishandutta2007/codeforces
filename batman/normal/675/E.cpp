#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =101*1000;

ll n,a[N],dp[N],ans=1;
pair <ll,ll> seg[4*N];

void build(ll xl,ll xr,ll id)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg[id]={a[xl],xl};return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	build(xl,mid,l);build(mid,xr,r);
	seg[id]={max(seg[l].first,seg[r].first),((seg[l].first>=seg[r].first)?seg[l].second:seg[r].second)};
}

pair <ll,ll> query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	//cout<<ql<<" "<<qr<<" "<<xl<<" "<<xr<<"\n";
	if(qr<=xl || xr<=ql)return {0,0};
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	pair <ll,ll> ex1=query(ql,qr,xl,mid,l);
	pair <ll,ll> ex2=query(ql,qr,mid,xr,r);
	return {max(ex1.first,ex2.first),((ex1.first>=ex2.first)?ex1.second:ex2.second)};
}

int main() 
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++)cin>>a[i];
	build(0,N,1);
	dp[n-1]=1;
	for(int i=n-2;i>=1;i--)
	{
		ll x=query(i+1,a[i]+1,0,N,1).second;
		dp[i]=dp[x]+n-a[i]+x-i;
		ans+=dp[i];
		
	}
	cout<<ans;
	return 0;
}