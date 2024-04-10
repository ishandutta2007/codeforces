#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =101*1000;

ll n,d,h[N],dp[N],par[N],seg[3*N],mp[N];
pair <ll,ll> a[N];

void update(ll q,ll xl,ll xr,ll id,ll num)
{
	if(xl>=xr)return ;
	if(xl==xr-1){if(dp[seg[id]]<dp[num])seg[id]=num;return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,l,num);
	else update(q,mid,xr,r,num);
	seg[id]=((dp[seg[l]]>dp[seg[r]])?seg[l]:seg[r]);
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2,lft=query(ql,qr,xl,mid,l),rght=query(ql,qr,mid,xr,r);
	return ((dp[lft]>dp[rght])?lft:rght);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n>>d;
   	for(int i=1;i<=n;i++)
   	{
   		cin>>h[i];
   		a[i]={h[i],i};
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i].first==a[i-1].first)mp[a[i].second]=mp[a[i-1].second];
		else mp[a[i].second]=i;
	}
	dp[1]=1;update(mp[1],0,N,1,1);
	for(int i=2;i<=n;i++)
	{
		ll l=0,r=n+1;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(a[mid].first>=h[i]+d)r=mid;
			else l=mid;
		}
		if(r!=n+1)par[i]=query(mp[a[r].second],N,0,N,1);
		l=0,r=n+1;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(a[mid].first<=h[i]-d)l=mid;
			else r=mid;
		}
		if(l!=0)
		{
			ll ex=query(0,mp[a[l].second]+1,0,N,1);
			if(dp[ex]>dp[par[i]])par[i]=ex;
		}
		dp[i]=dp[par[i]]+1,update(mp[i],0,N,1,i);
	}
	
	ll maxi=0;
	for(int i=1;i<=n;i++)
		if(dp[i]>dp[maxi])
			maxi=i;
	cout<<dp[maxi]<<"\n";
	stack <ll> ans;
	while(maxi)
	{
		ans.push(maxi);
		maxi=par[maxi];
	}
	while(ans.size())cout<<ans.top()<<" ",ans.pop();
	return 0;
}