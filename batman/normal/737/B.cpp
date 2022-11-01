#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,a,b,k,sum;
vector <pair<ll,ll> > v;
vector <ll> ans;
string s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n>>a>>b>>k>>s;
   	for(int i=0,len=0;i<=n;i++)
   	{
   		if(i==n)
   		{
   			v.push_back({i-len,i-1});sum+=len/b;
   			break;
		}
   		if(s[i]=='1')v.push_back({i-len,i-1}),sum+=len/b,len=0;
   		else len++;
	}
	sort(v.begin(),v.end());
	for(auto u:v)
	{
		if((u.second-u.first+1)/b<=0)continue;
		u.first++;u.second++;
		ll now=u.first+b-1;
		while(sum>=a && now<=u.second)
		{
			ans.push_back(now);
			sum--;
			now+=b;
		}
	}
	cout<<ans.size()<<"\n";
	for(auto u:ans)cout<<u<<" ";
	return 0;
}