#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
#define N (600)
#define INF ((ll)1e9)

string s[N];
ll n;

void dp(ll x)
{
	if(x==n+1)return ;
	ll ex=tavan(2,x-1);
	for(ll i=ex+1;i<=ex*2;i++)
		s[i]=s[i-ex];
	for(ll i=1;i<=ex;i++)
		for(ll j=0;j<ex;j++)
			s[i]+=s[i][j];	
	for(ll i=ex+1;i<=ex*2;i++)
		for(ll j=0;j<ex;j++)
			s[i]+=((s[i-ex][j]=='+')?'*':'+');
	dp(x+1);		
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    s[1]="+";
    dp(1);
	for(int i=1;i<=tavan(2,n);i++)
		cout<<s[i]<<"\n";		
    return 0;
}