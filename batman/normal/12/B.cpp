#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

string s,t;
ll num[10],mini=INF;

int main() 
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
	{
		ll ex=(ll)(s[i]-'0');
		num[ex]++;
		if(ex && ex<mini)mini=ex;
	}
	string ex="";
	if(mini!=INF)ex+=(char)(mini+'0'),num[mini]--;
	for(int i=0;i<10;i++)
		while(num[i]>0)
			ex+=(char)(i+'0'),num[i]--;
	//cout<<ex<<"\n";
	cout<<((ex==t)?"OK":"WRONG_ANSWER");
	
	
	return 0;
}