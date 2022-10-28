#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;
 
#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
	string s;
	cin>>s;
	ll n=s.size();
	ll countB=0,countu=0,countl=0,countbs=0,counta=0,counts=0,countr=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='B')
		{
			countB++;
		}
		if(s[i]=='u')
		{
			countu++;
		}
		if(s[i]=='l')
		{
			countl++;
		}
		if(s[i]=='b')
		{
			countbs++;
		}
		if(s[i]=='a')
		{
			counta++;
		}
		if(s[i]=='s')
		{
			counts++;
		}
		if(s[i]=='r')
		{
			countr++;
		}
	}
	counta=counta/2;
	countu=countu/2;
	ll ans=Min(countB,countu,countl);
	ans=Min(ans,countbs,counta);
	ans=Min(ans,counts,countr);
	cout<<ans;	
	return 0;
}