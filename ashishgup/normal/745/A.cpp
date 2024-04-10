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
    vector<string> v(n);
    v[0]=s;
    for(ll i=1;i<n;i++)
    {
    	s=s[n-1]+s;
    	s.erase(s.begin()+n);
    	v[i]=s;
	}
	ll count=1;
	for(ll i=1;i<n;i++)
	{
		bool check=true;
		for(ll j=0;j<i;j++)
		{
			if(v[i]==v[j])
			{
				check=false;
				break;
			}
		}
		if(check)
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}