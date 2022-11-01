#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll ax,ay,bx,by,tx,ty,n;
pair <ld,ll> a[N],b[N];
ld ans,mini;


int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ax>>ay>>bx>>by>>tx>>ty>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		ld p=(ld)sqrt((ld)(x-tx)*(x-tx)+(ld)(y-ty)*(y-ty));
		ans+=p*2;
		ld ex1=(ld)sqrt((ld)(x-ax)*(x-ax)+(ld)(y-ay)*(y-ay))-p;
		ld ex2=(ld)sqrt((ld)(x-bx)*(x-bx)+(ld)(y-by)*(y-by))-p;
		a[i]={ex1,i};
		b[i]={ex2,i};
	}
	//cout<<ans<<"\n";
	sort(a,a+n);sort(b,b+n);
	mini=min(a[0].first,b[0].first);
	if(b[0].second!=a[0].second)mini=min(mini,b[0].first+a[0].first);
	else mini=min(mini,min(a[0].first+b[1].first,a[1].first+b[0].first));
	cout<<fixed<<setprecision(12)<<ans+mini;
	
	
	return 0;
}