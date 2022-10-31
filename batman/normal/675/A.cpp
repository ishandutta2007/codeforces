#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll a,b,c;

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c;
	if(a==b && c==0)cout<<"YES";
	else if(c<0 && b<=a && ((b%(-c))+(-c))%(-c)==((a%(-c))+(-c))%(-c))cout<<"YES";
	else if(c>0 && b>=a && ((b%c)+c)%c==((a%c)+c)%c)cout<<"YES";
	else cout<<"NO";
	
	return 0;
}