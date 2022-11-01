#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)2e18)
#define MOD ((ll)1e9+7)
#define HASH (37)

ll n,p=2,b,e;
char a[2];
string s,t;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s>>t;
	for(;b<n && s[b]==t[b];b++);
	for(e=n-1;e>=0 && s[e]==t[e];e--);
	for(int i=b;i<e;i++)
		if(s[i]!=t[i+1])
		{
			p--;
			break;
		}
	for(int i=b;i<e;i++)
		if(t[i]!=s[i+1])
		{
			p--;
			break;
		}	
	cout<<p;
    return 0;
}