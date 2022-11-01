#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,ans;
vector <ll> x;


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--)
	{
		ll a;
		cin>>a;
		if(a%2==0)ans+=a;
		else
			x.push_back(a);
	}
	sort(x.begin(),x.end());
	for(int i=(ll)x.size()-1;i>=(ll)x.size()%2;i--)ans+=x[i];
	cout<<ans;
	
    return 0;
}