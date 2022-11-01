#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)301*1000);
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);

ll a,b,n;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(x<y)b++;
		else if(x>y)a++;
	}
	if(a==b)cout<<"Friendship is magic!^^";
	else
	{
		cout<<((a>b)?"Mishka":"Chris");
	}
	return 0;
}