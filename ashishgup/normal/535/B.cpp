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

vector<ll> v;

ll lucky(ll n)
{
	if(n>=1e9)
	{
		return n;
	}
	v.push_back(n);
	lucky(10*n+4);
	lucky(10*n+7);
	return 0;
}
int main()
{
	lucky(4);
	lucky(7);
	sort(v.begin(),v.end());
//	for(ll i=0;i<10;i++)
//	{
//		cout<<v[i]<<" ";
//	}
	//cout<<endl;
	ll n;
	cin>>n;
	ll ans=upper_bound(v.begin(),v.end(),n)-v.begin();
	cout<<ans;
	return 0;
}