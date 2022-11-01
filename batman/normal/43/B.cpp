#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define PI ((ld)3.141592653589793)
#define N (301*1000)

string s,t;
map <char,ll> mp;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	getline(cin,s);
	getline(cin,t);
	for(int i=0;i<s.size();i++)if(s[i]!=' ')mp[s[i]]++;
	for(int i=0;i<t.size();i++)
		if(t[i]!=' ')
		{
			if(mp[t[i]]==0)return cout<<"NO",0;
			mp[t[i]]--;
		}
	cout<<"YES";
	
	return 0;
}