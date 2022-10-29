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

ll n,a,b,c;
vector<ll> cache;
ll dp(ll i)
{
	if(i>n+1)
	{
		return -100000;
	}
	if(i==n+1)
	{
		return 0;
	}
	if(cache[i]!=-1)
	{
		return cache[i];
	}	
	cache[i]=Max(1+dp(i+a),1+dp(i+b),1+dp(i+c));
	return cache[i];
}
int main()
{
	cin>>n>>a>>b>>c;
	cache.resize(n+1,-1);
	ll ans=dp(1);
	cout<<ans;
    return 0;
}