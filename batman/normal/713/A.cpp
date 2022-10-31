#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll t;
map <ll,ll> mp;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		char c;
		cin>>c;
		if(c=='+')
	    {
	    	stack <ll> s;
	    	ll x;
	    	cin>>x;
	    	while(x)s.push(x%2),x/=10;
	    	while(s.size() && s.top()==0)s.pop();
	    	while(s.size())x=x*10+s.top(),s.pop();
	    	//cout<<"+ "<<x<<"\n";
	    	mp[x]++;
		}
		if(c=='-')
	    {
	    	stack <ll> s;
	    	ll x;
	    	cin>>x;
	    	while(x)s.push(x%2),x/=10;
	    	while(s.size() && s.top()==0)s.pop();
	    	while(s.size())x=x*10+s.top(),s.pop();
	    	//cout<<"- "<<x<<"\n";
	    	mp[x]--;
		}
		if(c=='?')
		{
			ll x=0,num;
			stack <ll> s;
			cin>>num;
			while(num)s.push(num%10),num/=10;
			while(s.size())x=x*10+s.top(),s.pop();
			cout<<mp[x]<<"\n";
		}
	}
	
	return 0;
}