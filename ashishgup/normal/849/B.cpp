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
const int inf=1e6;


int main()
{
	IOS;
	ll n;
	cin>>n;
	vll v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	ll x1=1;
	ll y1=v[0];
	for(ll i=1;i<n;i++)
	{
		ll x2=i+1;
		ll y2=v[i];
		vpll rem;
		for(ll j=0;j<n;j++)
		{
			ll x=j+1;
			ll y=v[j];
			ll eval=(x2-x1)*(y-y1) - (y2 - y1) * (x-x1);
			if(eval==0)				
			{
				continue;
			}
			rem.pb(mp(j+1,v[j]));
		}
		ll sz=rem.size();
		bool check=true;
		if(sz==0)
		{
			check=false;
		}
		else if(sz==1)
		{
			cout<<"Yes";
			return 0;
		}
		else
		{
			sort(rem.begin(),rem.end());
			ll x01=rem[0].ff;
			ll y01=rem[0].ss;
			ll x02=rem[1].ff;
			ll y02=rem[1].ss;
			ll left1=(y2 - y1) * (x02-x01);
			ll right1=(y02-y01) * (x2 - x1);
			if(left1!=right1)
			{
				check=false;
				continue;
			}
			for(ll j=2;j<sz;j++)
			{
				ll x=rem[j].ff;
				ll y=rem[j].ss;
				ll eval=(x02-x01)*(y-y01) - (y02 - y01) * (x-x01);
				if(eval!=0)
				{
					check=false;
				}
			}
		}
		if(check)
		{
			cout<<"Yes";
			return 0;
		}
	}
	x1=2;
	y1=v[1];
	for(ll i=2;i<n;i++)
	{
		ll x2=i+1;
		ll y2=v[i];
		vpll rem;
		for(ll j=0;j<n;j++)
		{
			ll x=j+1;
			ll y=v[j];
			ll eval=(x2-x1)*(y-y1) - (y2 - y1) * (x-x1);
			if(eval==0)				
			{
				continue;
			}
			rem.pb(mp(j+1,v[j]));
		}
		ll sz=rem.size();
		bool check=true;
		if(sz==0)
		{
			check=false;
		}
		else if(sz==1)
		{
			cout<<"Yes";
			return 0;
		}
		else
		{
			sort(rem.begin(),rem.end());
			ll x01=rem[0].ff;
			ll y01=rem[0].ss;
			ll x02=rem[1].ff;
			ll y02=rem[1].ss;
			ll left1=(y2 - y1) * (x02-x01);
			ll right1=(y02-y01) * (x2 - x1);
			if(left1!=right1)
			{
				check=false;
				continue;
			}
			for(ll j=2;j<sz;j++)
			{
				ll x=rem[j].ff;
				ll y=rem[j].ss;
				ll eval=(x02-x01)*(y-y01) - (y02 - y01) * (x-x01);
				if(eval!=0)
				{
					check=false;
				}
			}
		}
		if(check)
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}