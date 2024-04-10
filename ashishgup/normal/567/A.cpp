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
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	cout<<v[1]-v[0]<<" "<<v[n-1]-v[0]<<endl;
	for(ll i=1;i<n-1;i++)
	{
		ll min1=min(v[i+1]-v[i],v[i]-v[i-1]);
		ll max1=max(v[n-1]-v[i],v[i]-v[0]);
		cout<<min1<<" "<<max1<<endl;	
	}
	cout<<v[n-1]-v[n-2]<<" "<<v[n-1]-v[0];	
	return 0;
}