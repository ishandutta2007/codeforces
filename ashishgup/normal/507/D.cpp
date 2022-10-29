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
 
const int N=1e5+5;
 
ll n,k,m;
ll cache[1001][101][2];
int vis[1001][101][2];
ll dp(ll i,ll rem, int nonzerocheck)
{
	if(i==0)
	{
		if(rem==0&&nonzerocheck)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(vis[i][rem][nonzerocheck])
	{
		return cache[i][rem][nonzerocheck];
	}
	vis[i][rem][nonzerocheck]=1;
	if(rem==0&&nonzerocheck)
	{
		ll store=pow(10LL,i-1,m);
		store*=9;
		store%=m;
		cache[i][rem][nonzerocheck]=store;
		return store;
	}
	ll store=pow(10LL,n-i,k);
	for(ll j=0;j<=9;j++)
	{
		ll cur=store*j;
		cur%=k;
		if(j==0)
			cache[i][rem][nonzerocheck]+=dp(i-1,(rem+cur)%k,nonzerocheck);
		else
			cache[i][rem][nonzerocheck]+=dp(i-1,(rem+cur)%k,1);
		cache[i][rem][nonzerocheck]%=m;
	}
	return cache[i][rem][nonzerocheck];
}
int main()
{
	IOS;
	cin>>n>>k>>m;
	ll ans=0;
	for(ll i=0;i<=9;i++)
	{
		if(i==0)
			ans+=dp(n-1,i%k,0);
		else
			ans+=dp(n-1,i%k,1);
		ans%=m;
	}
	cout<<ans;
	return 0;
}