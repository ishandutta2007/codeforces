#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll a,b,c,d;

void check(ll x,ll y)
{
	//cout<<x<<" "<<y;
	ll ans=0;
	while(x%3==0 && a%3==0)
		a/=3,a*=2,x/=3,x*=2,ans++;
	while(x%3==0 && b%3==0)
		b/=3,b*=2,x/=3,x*=2,ans++;	
	while(y%3==0 && c%3==0)
		c/=3,c*=2,y/=3,y*=2,ans++;
	while(y%3==0 && d%3==0)
		d/=3,d*=2,y/=3,y*=2,ans++;	
	
	ll p=__gcd(x,y);
	x/=p,y/=p;	
				
	while(x%2==0 && a%2==0)
		a/=2,x/=2,ans++;	
	while(x%2==0 && b%2==0)
		b/=2,x/=2,ans++;
	while(y%2==0 && c%2==0)
		c/=2,y/=2,ans++;
	while(y%2==0 && d%2==0)
		d/=2,y/=2,ans++;
	if(x!=1 || y!=1)
	{
		cout<<-1;
		exit(0);	
	}
	cout<<ans<<"\n"<<a<<" "<<b<<"\n"<<c<<" "<<d;
				
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
	ll p=__gcd(a*b,c*d);
	//cout<<p<<endl;
	ll x=a*b/p,y=c*d/p;
	check(x,y);	
    return 0;
}