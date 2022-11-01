#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}


ll n,ans;

bool check(ll x)
{
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==2)return cout<<1,0;
	if(n%2==0)return cout<<2,0;
	if(check(n))return cout<<1,0;
	if(check(n-2))return cout<<2,0;
	cout<<3;
	return 0;
}