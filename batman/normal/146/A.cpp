#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

string s;
ll n[2],p;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>p;
	cin>>s;
	for(int i=0;i<p;i++)
	{
		if(s[i]!='4' && s[i]!='7')return cout<<"NO",0;
		n[i/(p/2)]+=(s[i]-'0');
	}
	cout<<((n[0]==n[1])?"YES":"NO");
    return 0;
}