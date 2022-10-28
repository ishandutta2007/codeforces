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


ll n;
string s;
vll v;
ll cache[40][20][20];
ll path[40][20][20];
vll pow10;

ll dp(ll i,ll a,ll b)
{
	if(i>=2*n)
	{	
		return 0;
	}	
	if(cache[i][a][b]!=-1)
	{
		return cache[i][a][b];
	}
	if(a==n)
	{
		cache[i][a][b]=v[i]*pow10[n-1-b]+dp(i+1,a,b+1);
		path[i][a][b]=2;
	}
	else if(b==n)
	{
		cache[i][a][b]=v[i]*pow10[n-1-a]+dp(i+1,a+1,b);
		path[i][a][b]=1;
	}
	else
	{
		ll pos1=v[i]*pow10[n-1-a]+dp(i+1,a+1,b);
		ll pos2=v[i]*pow10[n-1-b]+dp(i+1,a,b+1);
		cache[i][a][b]=max(pos1,pos2);
		if(pos1>pos2)
		{
			path[i][a][b]=1;
		}
		else
		{
			path[i][a][b]=2;
		}
	}
	return cache[i][a][b];
}
int main()
{
	IOS;
	cin>>n;
	cin>>s;
	v=vll(2*n);
	memset(cache,-1,sizeof(cache));
	memset(path,-1,sizeof(path));
	pow10=vll(19,1);
	for(ll i=1;i<=18;i++)
	{
		pow10[i]=pow10[i-1]*10;
	}
	for(ll i=0;i<2*n;i++)
	{
		v[i]=s[i]-'0';
	}
	ll ans=dp(0,0,0);
	cerr<<ans<<endl;
	ll ind=0;
	ll j=0,k=0;
	while(ind<2*n)
	{
		if(path[ind][j][k]==1)
		{
			j++;
			ind++;
			cout<<"H";
		}
		else
		{
			k++;
			ind++;
			cout<<"M";
		}
	}
	return 0;
}