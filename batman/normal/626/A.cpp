#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (202)

ll n,x,y,ans;
string s;
map <pair<ll,ll>,ll> mp;


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	mp[{0,0}]=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
		if(s[i]=='R')x++;
		if(s[i]=='L')x--;
		ans+=mp[{x,y}];
		mp[{x,y}]++;
	}
	cout<<ans;
	
	
	return 0;
}