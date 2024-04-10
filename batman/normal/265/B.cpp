#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,p,ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		ans+=abs(a-p);p=a;
	}		
	cout<<ans+2*n-1;
    return 0;
}