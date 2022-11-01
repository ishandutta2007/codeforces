#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll tavan(ll a,ll b){return b?(tavan((a*a)%n,b/2)*((b%2)?a:1))%n:1;}
int main()
{
	cin>>n;
	if(n==4)return cout<<"YES\n1\n3\n2\n4",0;
	for(ll i=2;i*i<=n;i++)if(n%i==0)return cout<<"NO",0;
	cout<<"YES\n1\n";
	for(ll i=2;i<n;i++)cout<<((i-1)*tavan(i,n-2))%n<<"\n";
	if(n>1)cout<<n;
	return 0;
}