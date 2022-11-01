#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e18)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}


ll a,b,k,prime[N];
vector <ll> v;

bool check(ll x)
{
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

ll calc(ll n,ll x)
{
	if(n<=x)return n==x;
	n/=x;
	ll res=n;
	for(auto u:v)
	{
		if(u>=x)break;
		res-=calc(n,u);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>a>>b>>k;
	if(!check(k))return cout<<0,0;
	if(k>=(ll)1e5)return cout<<(a<=k && k<=b),0;
	for(ll i=2;i<=k;i++)
		if(!prime[i])
		{
			v.push_back(i);
			for(ll j=i*i;j<=k;j+=i)
				prime[j]=1;
		}
	
	cout<<calc(b,k)-calc(a-1,k);
	return 0;
}