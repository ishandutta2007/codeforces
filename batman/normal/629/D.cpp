#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define PI ((ld)3.1415926535897)

ll n;
pair <ll,ll> a[N];
ll fen[N],ans,res[N];


ld query(ll x){ll num=0;for(;x>0;x-=x&(-x))num=max(num,fen[x]);return num;}
void add(ll x,ll y){for(;x<=n;x+=x&(-x))fen[x]=max(fen[x],y);}

int main()
{ 
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll h,r;
		cin>>r>>h;
		a[i]={r*r*h,i};
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;)
	{
		ll j=i,ex=a[i].first;
		while(a[j].first==ex && j<=n)
		{
			res[j]=a[j].first+query(a[j].second);
			ans=max(ans,res[j]);
			j++;
		}
		j=i;
		while(a[j].first==ex && j<=n)
		{
			add(a[j].second,res[j]);
			j++;
		}
		i=j;
	}
	cout<<fixed<<setprecision(12)<<ans*(ld)PI;
    return 0;
}