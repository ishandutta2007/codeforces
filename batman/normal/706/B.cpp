#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+9);
const ll HASH=36;

ll n,q,a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		cout<<upper_bound(a,a+n,x)-a<<"\n";
	}
	return 0;
}