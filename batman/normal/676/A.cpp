#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,p[2];

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		if(a==1)p[0]=i;
		if(a==n)p[1]=i;
	}
	if(p[0]>p[1])swap(p[0],p[1]);
	cout<<max(n-1-p[0],p[1]);
	
	return 0;
}