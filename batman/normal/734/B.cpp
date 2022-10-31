#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll a2,a3,a5,a6,ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a2>>a3>>a5>>a6;
	ll x=a3,y=min(a5,a6);
	for(ll i=0;i<=a2;i++)
	{
		ans=max(ans,min(x,i)*32+256*min(a2-i,y));
	}
	cout<<ans;
	return 0;
}