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

const int N=5e3+5;

string s;
int cache[N][N];
int vis[N][N];
ll n;

ll dp(ll i,ll j)
{
	if(i>j)
	{
		return 1;
	}
	if(vis[i][j])
	{
		return cache[i][j];
	}
	if(i==j)
	{
		vis[i][j]=1;
		cache[i][j]=1;
		return cache[i][j];
	}
	vis[i][j]=1;
	if(s[i]==s[j])
	{
		cache[i][j]=dp(i+1,j-1);
	}
	else
	{
		cache[i][j]=0;
	}
	return cache[i][j];
}
int main()
{
	IOS;
	cin>>s;
	ll q;
	cin>>q;
	n=s.size();
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			dp(i,j);
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=i;j<n;j++)
		{
			cache[i][j]+=cache[i][j-1];
		}
	}
	for(ll i=1;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cache[i][j]+=cache[i-1][j];
		}
	}
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		l--;
		r--;
		ll store=cache[n-1][r];
		ll subt;
		if(l>=1)
			subt=cache[l-1][r];
		else
			subt=0;
		store-=subt;
		cout<<store<<endl;
	}

	return 0;
}