//Started 5 mins late

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

typedef struct sofa
{
	ll x1,y1,x2,y2,id;
}nd;

int main()
{
	IOS;
	ll d;
	cin>>d;
	vector<nd> v(d);
	ll n,m;
	cin>>n>>m;
	ll cl,cr,cu,cd;
	vll xleft(n+1,0);
	vll xright(n+1,0);
	vll yup(m+1,0);
	vll ydown(m+1,0);
	for(ll i=0;i<d;i++)
	{
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ll minx=min(x1,x2);
		ll maxx=max(x1,x2);
		xleft[minx]++;
		xright[maxx]++;
		v[i].x1=minx;
		v[i].x2=maxx;
		ll miny=min(y1,y2);
		ll maxy=max(y1,y2);
		yup[miny]++;
		ydown[maxy]++;
		v[i].y1=miny;
		v[i].y2=maxy;
		v[i].id=i;
	}
	cin>>cl>>cr>>cu>>cd;
	for(ll i=1;i<=n;i++)
	{
		xleft[i]+=xleft[i-1];
		xright[i]+=xright[i-1];
	}
	for(ll i=1;i<=m;i++)
	{
		yup[i]+=yup[i-1];
		ydown[i]+=ydown[i-1];
	}
	for(ll i=0;i<d;i++)
	{
		ll ctl=xleft[v[i].x2-1];
		if(v[i].x1<v[i].x2)
		{
			ctl--;
		}
		ll ctr=d-xright[v[i].x1];
		if(v[i].x2>v[i].x1)
		{
			ctr--;
		}
		ll ctu=yup[v[i].y2-1];
		if(v[i].y1<v[i].y2)
		{
			ctu--;
		}
		ll ctd=d-ydown[v[i].y1];
		if(v[i].y2>v[i].y1)
		{
			ctd--;
		}
		if(cl==ctl&&cr==ctr&&cu==ctu&&cd==ctd)
		{
			cout<<i+1;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}