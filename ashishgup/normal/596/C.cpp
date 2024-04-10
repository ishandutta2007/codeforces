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

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<long long> vll;
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
template<typename T> T pow(T a,ll b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a); b/=2; a=(a*a); } return ans; }

int main()
{
 	IOS;
 	ll n;
 	cin>>n;
 	set<pair<ll,pair<ll,ll> > > ans;
 	for(ll i=0;i<n;i++)
 	{
		ll x,y;
		cin>>x>>y; 		
		pair<ll,ll> p={x,y};
		ans.insert(mp(y-x,p));
	}
	vll v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vpll ans2;
	for(ll i=0;i<n;i++)
	{
		ll val=v[i];
		pair<ll,ll> p={0,0};
		pair<ll,pair<ll,ll>  > p2={val,p};
		auto it=ans.lower_bound(p2);
		if((*it).ff==val)
		{
			ans2.pb((*it).ss);
			ans.erase(it);
		}
		else
		{
		//	trace2(i,val);
			cout<<"NO";
			return 0;
		}
	}
	for(ll i=0;i<n-1;i++)
	{
		pll p1=ans2[i];
		pll p2=ans2[i+1];
		if(p1.ff>=p2.ff&&p1.ss>=p2.ss)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(auto it:ans2)
	{
		cout<<it.ff<<" "<<it.ss<<endl;
	}
	return 0;
}