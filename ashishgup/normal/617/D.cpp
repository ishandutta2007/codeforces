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

typedef long long ll;
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

int main()
{
	ll x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	ll ans;
	ll a=-1,b=1,c=0;
	if(x1==x2&&x2==x3)
	{
		ans=1;
		cout<<ans;
		return 0;
	}
	else if(y1==y2&&y2==y3)
	{
		ans=1;
		cout<<ans;
		return 0;
	}
	else if(x1==x2)
	{
		a=min(y1,y2);
		b=max(y1,y2);
		c=y3;
	}
	else if(x1==x3)
	{
		a=min(y1,y3);
		b=max(y1,y3);
		c=y2;
	}
	else if(x2==x3)
	{
		a=min(y2,y3);
		b=max(y2,y3);
		c=y1;
	}
	else if(y1==y2)
	{
		a=min(x1,x2);
		b=max(x1,x2);
		c=x3;
	}
	else if(y1==y3)
	{
		a=min(x1,x3);
		b=max(x1,x3);
		c=x2;
	}
	else if(y3==y2)
	{
		a=min(x3,x2);
		b=max(x3,x2);
		c=x1;
	}
	if(c>=b||c<=a)
	{
		ans=2;
	}
	else
	{
		ans=3;
	}
	cout<<ans;
}