#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (301*1000)

string s;
ll ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for(int i=0;i<(ll)s.size()-1;i++)
	{
		if(((s[i]-'0')*10+(s[i+1]-'0'))%4==0)ans+=i+1;
		if(s[i]=='0' || s[i]=='4' || s[i]=='8')ans++;
	}
	if(s[(ll)s.size()-1]=='0' || s[(ll)s.size()-1]=='4' || s[(ll)s.size()-1]=='8')ans++;
	cout<<ans;
	return 0;
}