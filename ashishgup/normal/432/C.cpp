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
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

vll v,ind;
void swap1(ll i,ll j)
{
	ll a=v[i];
	ll b=v[j];
	ind[a]=j;
	ind[b]=i;
	swap(v[i],v[j]);
}
int main()
{
	IOS;
	ll n;
	cin>>n;
	v=vll(n);
	ind=vll(n+1);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		v[i]--;
		ind[v[i]]=i;
	}
	vb sieve(1e5+1,true);
	sieve[0]=sieve[1]=false;
	set<ll> s;
	for(ll i=2;i<=1e5;i++)
	{
		if(sieve[i])
		{
			for(ll j=2;i*j<=1e5;j++)
			{
				sieve[i*j]=false;
			}
			s.insert(i);
		}
	}
	vpll ans;
	for(ll i=0;i<n;i++)
	{
		ll cur=ind[i];
		ll diff=ind[i]-i;
		while(diff>0)
		{
			auto it=s.upper_bound(diff+1);
			it--;
			ll st=*it;
			st--;
			diff-=st;
			ans.pb(mp(ind[i]-st,ind[i]));
			swap1(ind[i]-st,ind[i]);
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
	{
		cout<<it.ff+1<<" "<<it.ss+1<<endl;
	}
	return 0;
}