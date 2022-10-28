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
typedef long double ld;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

void mult(ll a[52][52], ll b[52][52], ll m)
{
	ll d[52][52];
	memset(d,0,sizeof(d));
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{
			for(ll k=0;k<m;k++)
			{
				d[i][j]+=a[i][k] * b[k][j];
				d[i][j]%=MOD;
			}
		}
	}
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{
			a[i][j]=d[i][j];
		}
	}
}

void exp(ll a[52][52], ll n, ll m)
{
	ll res[52][52];
	memset(res,0,sizeof(res));
	for(ll i=0;i<52;i++)
	{
		res[i][i]=1;
	}
	while(n>0)
	{
		if(n%2 == 1)
		{
			mult(res,a,m);
		}
		mult(a,a,m);
		n=n/2;
	}
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{
			a[i][j]=res[i][j];
		}
	}
}
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans[52][52];
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{
			ans[i][j]=1;
		}
	}
	for(ll i=0;i<k;i++)
	{
		char a,b;
		cin>>a>>b;
		ll a1=(a>='a'&&a<='z')?(a-'a'):(a-'A'+26);
		ll b1=(b>='a'&&b<='z')?(b-'a'):(b-'A'+26);
		ans[a1][b1]=0;
	}
	exp(ans, n-1, m);
	ll answer=0;
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{
			answer+=ans[i][j];
			answer%=MOD;
		}
	}
	cout<<answer;
}