#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,ans;
multiset <ll> s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		s.insert(x);
	}
	ll lst=0;
	while(s.size())
	{
		ll x=*s.begin(),y=s.count(x);s.erase(x);
		ans+=x-lst;
		if(y%2==0)ans++;
		for(int i=0;i<y/2;i++)s.insert(x+1);
		lst=x+1;
	}
	cout<<ans;
	return 0;
}