#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

string s,t;
ll n,m;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='4' && t[i]=='7')n++;
		if(s[i]=='7' && t[i]=='4')m++;
	}
	cout<<max(n,m);
    return 0;
}