#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =501*1000;

ll n,seg[4*N],id[N],ans;
pair <pair<ll,ll>,ll> a[N];
pair <ll,ll> b[N];

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(xr<=ql || qr<=xl)return 0;
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	return max(query(ql,qr,xl,mid,l),query(ql,qr,mid,xr,r));
}

void update(ll q,ll xl,ll xr,ll id,ll num)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg[id]=max(seg[id],num);return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,l,num);
	else update(q,mid,xr,r,num);
	seg[id]=max(seg[l],seg[r]);
}

int main() 
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].first.first);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].first.second);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].second);
	sort(a,a+n);
	for(int i=0;i<n;i++)
		b[i]={a[i].first.second,i};
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(i && b[i].first==b[i-1].first)id[b[i].second]=id[b[i-1].second];
		else id[b[i].second]=i;
	}
	
	for(int i=n-1;i>=0;i--)
	{
		ll j=i;
		while(j>0 && a[j].first.first==a[j-1].first.first)
		{
			if(query(id[j]+1,N,0,N,1)>a[j].second)
				ans++;
			j--;
		}
		if(query(id[j]+1,N,0,N,1)>a[j].second)
				ans++;
		j=i;
		while(j>0 && a[j].first.first==a[j-1].first.first)
		{
			update(id[j],0,N,1,a[j].second);
			j--;
		}
		update(id[j],0,N,1,a[j].second);
		i=j;
	}
	printf("%d",ans);
	return 0;
}