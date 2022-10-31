#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

string s[3];

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s[0]>>s[1]>>s[2];
	if(s[0][0]==s[2][2] && s[0][1]==s[2][1] && s[0][2]==s[2][0] && s[1][0]==s[1][2])cout<<"YES";
	else cout<<"NO";
	
	
	return 0;
}