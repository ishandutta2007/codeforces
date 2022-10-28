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


int main()
{
	IOS;
	ll n,k;
	cin>>n>>k;
	vll v(n);
	sort(v.begin(),v.end());
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	ll lo=1;
	ll hi=2e9;
	while(lo<hi)
	{
		ll mid=(lo+hi+1)/2;
		ll reqd=0;
		for(ll i=0;i<n;i++)
		{
			reqd+=max(0LL,mid-v[i]);
		}
		if(reqd<=k)
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	ll stk=k;
	for(ll i=0;i<n;i++)
	{
		stk-=max(0LL,lo-v[i]);
		v[i]=max(v[i],lo);
	}
	ll ind=0;
	while(stk>0)
	{
		if(v[ind]!=lo)
		{
			ind++;
			continue;
		}
		v[ind++]++;
		stk--;
	}
    lo=1;
	hi=2e9;
	sort(v.begin(),v.end());
	while(lo<hi)
	{
		ll mid=(lo+hi)/2;
		ll reqd=0;
		for(ll i=0;i<n;i++)
		{
			reqd+=max(0LL,v[i]-mid);
		}
		if(reqd<=k)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	stk=k;
	for(ll i=0;i<n;i++)
	{
		stk-=max(0LL,v[i]-lo);
		v[i]=min(v[i],lo);
	}
	ind=n-1;
	while(stk>0)
	{
		if(v[ind]!=lo)
		{
			ind++;
			continue;
		}
		v[ind--]--;
		stk--;
	}
	ll min1=LLONG_MAX;
	ll max1=LLONG_MIN;
	for(ll i=0;i<n;i++)
	{
		min1=min(min1,v[i]);
		max1=max(max1,v[i]);
	}
	cout<<max1-min1;
	return 0;
}