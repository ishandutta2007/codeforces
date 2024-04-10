//Started 5 minutes late

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
	ll n,m;
	cin>>n>>m;
	vvc v(n,vc(m));
	map<char,ll> m1;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>v[i][j];
			m1[v[i][j]]++;
		}
	}
	map<ll,ll> m2;
	for(auto it:m1)
	{
		m2[it.ss]++;
	}
	if(m2.size()!=1|| m2.begin()->second != 3)
	{
		cout<<"NO";
		return 0;
	}
	if(n%3==0)
	{
		set<char> s;
		for(ll i=0;i<n/3;i++)
		{
			for(ll j=0;j<m;j++)
			{
				s.insert(v[i][j]);
			}
		}
		set<char> s2;
		for(ll i=n/3;i<2* (n/3);i++)
		{
			for(ll j=0;j<m;j++)
			{
				s2.insert(v[i][j]);
			}
		}
		set<char> s3;
		for(ll i=2 * (n/3); i<n; i++)
		{
			for(ll j=0;j<m;j++)
			{
				s3.insert(v[i][j]);
			}
		}
		if(s.size()==1&&s2.size()==1&&s3.size()==1)
		{
			cout<<"YES";
			return 0;
		}
	}
	if(m%3==0)
	{
		set<char> s;
		for(ll i=0;i<m/3;i++)
		{
			for(ll j=0;j<n;j++)
			{
				s.insert(v[j][i]);
			}
		}
		set<char> s2;
		for(ll i=m/3;i<2* (m/3);i++)
		{
			for(ll j=0;j<n;j++)
			{
				s2.insert(v[j][i]);
			}
		}
		set<char> s3;
		for(ll i=2 * (m/3); i<m; i++)
		{
			for(ll j=0;j<n;j++)
			{
				s3.insert(v[j][i]);
			}
		}
		if(s.size()==1&&s2.size()==1&&s3.size()==1)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}