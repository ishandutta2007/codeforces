#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tofan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll a,b,c;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c;
	ld ex=(ld)b/(b+c);
	ld ans=(ld)a*ex;
	cout<<fixed<<setprecision(10)<<ans<<endl;
	
	
	
    return 0;
}