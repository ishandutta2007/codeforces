#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,seg[4*N],dp[N],ans[N];
pair <ll,pair<ll,ll> > a[N];

void update(ll q,ll xl,ll xr,ll id)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg[id]=q;return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,l);
	else update(q,mid,xr,r);
	seg[id]=((seg[l]+dp[seg[l]]-1>seg[r]+dp[seg[r]]-1)?seg[l]:seg[r]);
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	ll ex1=query(ql,qr,xl,mid,l),ex2=query(ql,qr,mid,xr,r);
	if(ex1+dp[ex1]-1>ex2+dp[ex2]-1)return ex1;
	return ex2;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second.first,a[i].second.second=i;
	sort(a,a+n);
	dp[n-1]=1;
	update(n-1,0,N,1);
	for(int i=n-2;i>=0;i--)
	{
		ll l=i,r=n;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(a[mid].first<a[i].first+a[i].second.first)l=mid;
			else r=mid;
		}
		ll ex=query(i+1,l+1,0,N,1);
		dp[i]=max(l-i+1,dp[ex]+ex-i);
		update(i,0,N,1);
	}
	for(int i=0;i<n;i++)ans[a[i].second.second]=dp[i];
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}