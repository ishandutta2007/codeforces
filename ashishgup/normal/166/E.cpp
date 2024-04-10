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

void mult(ll a[4][4],ll b[4][4])
{
	ll d[4][4];
	memset(d,0,sizeof(d));
	for(ll i=0;i<4;i++)
	{
		for(ll j=0;j<4;j++)
		{
			for(ll k=0;k<4;k++)
			{
				d[i][j]+=a[i][k]*b[k][j];
				d[i][j]%=MOD;
			}
		}
	}
	for(ll i=0;i<4;i++)
	{
		for(ll j=0;j<4;j++)
		{
			a[i][j]=d[i][j];
		}
	}
}
void exp(ll a[4][4],ll n)
{
	ll res[4][4];
	memset(res,0,sizeof(res));
	for(ll i=0;i<4;i++)
	{
		res[i][i]=1;
	}
	while(n>0)
	{
		if(n%2==1)
		{
			mult(res,a);
		}
		mult(a,a);
		n=n/2;
	}
	for(ll i=0;i<4;i++)
	{
		for(ll j=0;j<4;j++)
		{
			a[i][j]=res[i][j];
		}
	}
}
int main()
{
	IOS;
	ll n;
	cin>>n;
	ll ans[4][4];
	for(ll i=0;i<4;i++)
	{
		for(ll j=0;j<4;j++)
		{
			if(i==j)
				ans[i][i]=0;
			else
				ans[i][j]=1;	
		}
	}
	exp(ans,n);
	cout<<ans[0][0];
	return 0;
}