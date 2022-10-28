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
	ll n;
	cin>>n;
	vector<ll> v(n);
	vector<ll> v2(n,0);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	string s="";
	for(ll i=0;i<n-1;i++)
	{
		ll diff=v[i]-v2[i]-1;
		for(ll j=0;j<diff;j++)
		{
			s+="PRL";
		}
		if(diff>=0)
		{
			s=s+"P";
		}
		s=s+"R";
	}
	while(v2[n-1]!=v[n-1])
	{
		s=s+"P";
		v2[n-1]++;
		if(v2[n-1]!=v[n-1])
		{
			s=s+"LR";
		}
	}
	cout<<s;
	return 0;
}