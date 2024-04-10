#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}


ll n,m,a[N],b[N],last[N];

bool check(ll x)
{
	for(int i=1;i<=m;i++)last[i]=-1;
	for(int i=0;i<x;i++)
		last[a[i]]=i;
	for(int i=1;i<=m;i++)if(last[i]==-1)return 0;
	for(int i=x-1,use=x-1;i>=0;i--,use=min(use,i))
	{
		if(a[i]==0 || i!=last[a[i]])continue;
		use-=b[a[i]]+1;
		if(use<-1)return 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	ll l=0,r=n+1;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(r==n+1)cout<<-1;
	else cout<<r;
	return 0;
}