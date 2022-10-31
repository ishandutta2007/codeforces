#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,a,b,c,d,p[5],ans;

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b>>c>>d;
	
		p[0]=0;
		p[1]=b-c;
		p[3]=a-d;
		p[4]=a+b-c-d;
		ll mini=min(p[0],min(p[1],min(p[3],p[4])));
		ll maxi=max(p[0],max(p[1],max(p[3],p[4])));
		ll left=-mini+1;
		ll right=n-maxi;
	cout<<max(n*(right-left+1),0ll);
	return 0;
}