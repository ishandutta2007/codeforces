#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (111)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ld PI=(ld)2*asin(1);
ll n,a[N];
ld ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	for(int i=n;i>0;i-=2)
	{
		ans+=a[i]*a[i]*PI-a[i-1]*a[i-1]*PI;
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}