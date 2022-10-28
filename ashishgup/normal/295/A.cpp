#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
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
 

int main()
{
	IOS;
	ll n,m,k;
	cin>>n>>m>>k;
	vll v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vll l(m),r(m),val(m);
	for(ll i=0;i<m;i++)
	{
		cin>>l[i]>>r[i]>>val[i];
		l[i]--;
		r[i]--;
	}
	vll v2(m+1,0);
	for(ll i=0;i<k;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		v2[a]++;
		v2[b+1]--;
	}
	for(ll i=1;i<=m;i++)
	{
		v2[i]+=v2[i-1];
	}
	vll v3(n+1,0);
	for(ll i=0;i<m;i++)
	{
		ll num=v2[i];
		ll lind=l[i];
		ll rind=r[i];
		ll inc=val[i]*num;
		v3[lind]+=inc;
		v3[rind+1]-=inc;
	}
	for(ll i=1;i<=n;i++)
	{
		v3[i]+=v3[i-1];
	}
	for(ll i=0;i<n;i++)
	{
		cout<<v[i]+v3[i]<<" ";
	}
	return 0;
}