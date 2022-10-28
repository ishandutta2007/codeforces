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

typedef long double ld;
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

string a;
string b;
ll n;
vector<string> v;
vector<string> v2;

vector<string> rec(vector<string> p)
{
	if(p.size()==1)
	{
		return p;
	}
	vector<string> p1;
	vector<string> p2;
	ll sz=p.size();
	for(ll i=0;i<sz/2;i++)
	{
		p1.pb(p[i]);
	}
	for(ll i=sz/2;i<sz;i++)
	{
		p2.pb(p[i]);
	}
	p1=rec(p1);
	p2=rec(p2);
	if(p1<p2)
	{
		p1.insert(p1.end(),p2.begin(),p2.end());
		return p1;
	}
	else
	{
		p2.insert(p2.end(),p1.begin(),p1.end());
		return p2;
	}
}
int main()
{
	IOS;
	cin>>a>>b;
	n=a.size();
	ll st=n;
	while(st%2==0)
	{
		st/=2;
	}
	for(ll i=0;i<n;i+=st)
	{
		string s=a.substr(i,st);
		v.pb(s);
		s=b.substr(i,st);
		v2.pb(s);
	}
	if(rec(v)==rec(v2))
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}