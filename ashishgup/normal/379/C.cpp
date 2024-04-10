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

bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.second!=b.second)
	{
		return a.second<b.second;
	}
	else
	{
		return a.first<b.first;
	}
}
int main()
{
	ll n;
	cin>>n;
	vector< pair<ll,ll> > v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].first;
		v[i].second=i;
	}
	sort(v.begin(),v.end());
	for(ll i=1;i<n;i++)
	{
		if(v[i].first<=v[i-1].first)
		{
			v[i].first=v[i-1].first+1;
		}
	}
	sort(v.begin(),v.end(),myComparison);
	for(ll i=0;i<n;i++)
	{
		cout<<v[i].first<<" ";
	}
	return 0;
}