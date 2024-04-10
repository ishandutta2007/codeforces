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
	ll k;
	cin>>k;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		if(i>0)
		{
			v[i]+=v[i-1];
		}
	}
	ll min1=v[k-1];
	ll index=1;
	for(ll i=k;i<n;i++)
	{
		ll temp=v[i]-v[i-k];
		if(temp<min1)
		{
			min1=temp;
			index=i-(k-2);
		}
	}
	cout<<index;
	return 0;
}