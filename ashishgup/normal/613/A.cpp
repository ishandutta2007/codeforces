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

ld dist1(ld x1,ld y1, ld x2,ld y2)
{
	return (ld)sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

ld dist2(ld x1, ld y1, ld x2, ld y2, ld x, ld y)
{
	ld num=(y2-y1)*x - (x2-x1)*y + x2*y1 - y2*x1;
	ld den=dist1(x1,y1,x2,y2);
	num=abs(num);
	return (ld)num/den;
}

typedef struct node
{
	ld x,y;
}nd;

bool func(ld x1, ld y1,ld x2,ld y2, ld x3,ld y3)
{
	if(x3>x1&&x3>x2||y3>y1&&y3>y2||y3<y1&&y3<y2||x3<x1&&x3<x2)
		return false;
	return true;
}
ld k(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	ld ans=(y2-y1)*(x3-x1) - (x2-x1)*(y3-y1);
	ld den=(y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
	ans/=den;
	return ans;
}

int main()
{
	IOS;
	ll n,x,y;
	cin>>n>>x>>y;
	vector<nd> v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].x>>v[i].y;
	}
	ld min1=LLONG_MAX;
	ld max1=0;
	for(ll i=0;i<n;i++)
	{
		ld dist=dist1(x,y,v[i].x,v[i].y);
		min1=min(min1,dist);
		max1=max(max1,dist);
		ld x1=v[i].x;
		ld y1=v[i].y;
		ld x2=v[(i+1)%n].x;
		ld y2=v[(i+1)%n].y;
		ld st=k(x1,y1,x2,y2,x,y);
		ld x4=x-st*(y2-y1);
		ld y4=y+st*(x2-x1);
		bool check=func(x1,y1,x2,y2,x4,y4);
		if(check)
			min1=min(min1,dist2(v[i].x,v[i].y,v[(i+1)%n].x,v[(i+1)%n].y,x,y));
	}
	trace2(max1,min1);
	ld ans=PI*(max1*max1-min1*min1);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
	
}