#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int main()
{
	cin>>n;
	ll d=min(50ll,n);
	for(ll i=0;i<d;i++)
		for(ll j=0;j<d;j++)
			for(ll k=0;k<d;k++)
				ans=max(ans,lcm(n-i,lcm(n-j,n-k)));
	cout<<ans;
	return 0;
}