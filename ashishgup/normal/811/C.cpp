#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef int ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

ll n;
vll v;
vll first(5001,-1);
vll last(5001,-1);
vll cache(5001,-1);
ll dp(ll i)
{
	if(i>=n)
		return 0;
	if(cache[i]!=-1)
		return cache[i];
	ll f=first[v[i]];
	ll l=last[v[i]];
	ll f2=f,l2=l;
	set<ll> s;
	for(ll it=f;it<=l;it++)
	{
		f2=min(f2,first[v[it]]);
		l2=max(l2,last[v[it]]);
	}
	if(f2<i)
	{
		cache[i]=dp(i+1);
		return cache[i];
	}
	for(ll it=f2;it<=l2;it++)
	{
		s.insert(v[it]);
	}
	ll stxor=0;
	for(auto it:s)
	{
		stxor^=it;
	}
	cache[i]=dp(i+1);
	cache[i]=max(cache[i],stxor+dp(l2+1));
	return cache[i];
}
int main()
{
	IOS;
	cin>>n;
	v=vll(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		if(first[v[i]]==-1)
		{
			first[v[i]]=i;
		}
		last[v[i]]=i;
	}
	ll ans=dp(0);
	cout<<ans;
	return 0;
}