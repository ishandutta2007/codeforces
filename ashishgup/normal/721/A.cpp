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
	string s;
	cin>>s;
	ll count=0;
	vector<ll> v;
	ll len=0;
	if(s[0]=='B')
	{
		count++;
		len++;
	}
	for(ll i=1;i<n;i++)
	{
		if(s[i]=='B')
		{
			if(s[i-1]=='B')
			{
				len++;
			}
			else
			{
				len=1;
				count++;
			}
		}
		else
		{
			if(len>=1)
			{
				v.push_back(len);
			}
			len=0;
		}
	}
	if(len>=1)
	{
		v.push_back(len);
	}
	cout<<count<<endl;
	for(ll i=0;i<count;i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}