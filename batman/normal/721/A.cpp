#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)5050)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,now;
string s;
vector <ll> ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='B'){now++;continue;}
		if(now)ans.push_back(now);
		now=0;
	}
	if(now)ans.push_back(now);
	cout<<ans.size()<<"\n";
	for(auto x:ans)cout<<x<<" ";
	return 0;
}