#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)301*1000);
const ll INF=((ll)2e18);
const ll MOD=((ll)1e9+7);

ll n,m,x,y,ans;

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	ll ex=n-1;
	if(ex==0)x=1;
	while(ex)x++,ex/=7;
	ex=m-1;
	if(ex==0)y=1;
	while(ex)y++,ex/=7;
	if(x+y>7)return cout<<0,0;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
		{
			bool res=1;
			bool mark[7]={};
			ll ex=i;
			for(int q=0;q<x;q++){if(mark[ex%7])res=0;mark[ex%7]=1;ex/=7;}
			ex=j;
			for(int q=0;q<y;q++){if(mark[ex%7])res=0;mark[ex%7]=1;ex/=7;}
			ans+=res;
		}
	cout<<ans;
	return 0;
}