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
    vector<ll> x(n);
    vector<ll> y(n);
    vector<pair <ll,ll> > v(n);
    for(ll i=0;i<n;i++)
    {
    	cin>>x[i];
    	cin>>y[i];
    	v[i].first=x[i];
    	v[i].second=y[i];
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	sort(v.begin(),v.end());
	ll count=1;
	ll ansx=0;
	for(ll i=1;i<n;i++)
	{
		if(x[i]==x[i-1])
		{
			count++;
		}
		else
		{
			ansx+=((count)*(count-1))/2;
			count=1;
		}
	}
	ansx+=((count)*(count-1))/2;
	count=1;
	ll ansy=0;
	for(ll i=1;i<n;i++)
	{
		if(y[i]==y[i-1])
		{
			count++;
		}
		else
		{
			ansy+=((count)*(count-1))/2;
			count=1;
		}
	}
	ansy+=((count)*(count-1))/2;
	count=1;
	ll ansunion=0;
	for(ll i=1;i<n;i++)
	{
		if(v[i].first==v[i-1].first&&v[i].second==v[i-1].second)
		{
			count++;
		}
		else
		{
			ansunion+=((count)*(count-1))/2;
			count=1;
		}
	}
	ansunion+=((count)*(count-1))/2;
	ll finans=ansx+ansy-ansunion;
	cout<<finans;
	return 0;
}