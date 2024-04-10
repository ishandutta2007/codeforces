#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (20)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,id;
vector <ll> a,b;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(x!=0)a.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(x!=0)b.push_back(x);
		if(x==a[0])id=(ll)b.size()-1;
	}
	ll i=0;
	for(;id<n-1;id++,i++)
		if(b[id]!=a[i])
			return cout<<"NO",0;
	id=0;
	for(;i<n-1;id++,i++)
		if(b[id]!=a[i])
			return cout<<"NO",0;
	cout<<"YES";
	return 0;
}