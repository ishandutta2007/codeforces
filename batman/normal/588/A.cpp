//Platform Version 1.3.9
#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define ST(a,b) cout<<fixed<<setprecision((b))<<((ld)a)<<"\n";
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
inline ll tavan(ll a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ld tavan(ld a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll gcd(ll a,ll b){while(b ^= a ^= b ^= a = a % b);return a;}
ifstream fin("input.txt");
ofstream fout("output.txt");
const ld PI=((ld)2*asin(1));
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,ans,a,p;

int Sa1378
{
 	IB
 	cin>>n>>a>>p;
 	ans=a*p;
 	for(int i=1;i<n;i++)
	{
 		ll ex,ex2;
 		cin>>ex>>ex2;
 		if(ex2<=p) p=ex2;
 		ans+=ex*p;
 	}
 	cout<<ans;
 	return 0;
}