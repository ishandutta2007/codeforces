#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=301*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,a[2];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(x==100)a[0]++;
		else a[1]++;
	}
	if(a[0]%2==0 && a[1]%2==0)cout<<"YES";
	else if(a[1]%2==1 && (a[0]%2==0) && a[0]>=2)cout<<"YES";
	else cout<<"NO";
	return 0;
}