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

ll n,x,y;
vll v;
ll k;
ll stx,sty;
ll lcm1;

bool check(ld mid)
{
	ll attacka=floor(mid*x);
	ll attackb=floor(mid*y);
	if(attacka+attackb >= k)
		return true;
	else
		return false;
}

ll binsearch(ll lo,ll hi)
{
	while(lo<hi)
	{
		ll mid=(lo+hi)/2;
		ll atcka=mid/stx;
		ll atckb=mid/sty;
		if((atcka+atckb)>=k)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	return lo;
}
int main()
{
	IOS;
	cin>>n>>x>>y;
	v=vll(n);
	lcm1=(x*y)/(gcd(x,y));
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
    stx=lcm1/x;
	sty=lcm1/y;
	for(ll i=0;i<n;i++)
	{
		k=v[i];
		k%=(x+y);
		ll ans=binsearch(0,lcm1);
		if(ans%stx==0 && ans%sty==0)
		{
			cout<<"Both"<<endl;
		}
		else if(ans%stx==0)
		{
			cout<<"Vanya"<<endl;
		}
		else
		{
			cout<<"Vova"<<endl;
		}
	}
	return 0;
}