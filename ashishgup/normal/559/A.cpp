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

vector<ld> p(6);
vector<pair<ld,ld> > v(6);

ld distance(pair<ld,ld> p1,pair<ld,ld> p2)
{
	ld xdiff=p1.ff-p2.ff;
	ld ydiff=p1.ss-p2.ss;
	xdiff*=xdiff;
	ydiff*=ydiff;
	ld ans=(ld)sqrt(xdiff+ydiff);
	return ans;
}

ld heron(ld a,ld b,ld c)
{
	ld s=(a+b+c)/2;
	ld prod=(s)*(s-a)*(s-b)*(s-c);
	ld ans=(ld)sqrt(prod);
	return ans;
}
int main()
{
	IOS;
	for(ll i=0;i<6;i++)
	{
		cin>>p[i];
	}
	v[0]={0,0};
	ld angle=120;
	for(ll i=1;i<=5;i++)
	{
		ld radian=angle*((ld)PI/180);
		v[i].ff=v[i-1].ff+p[i-1]*(ld)cos(radian);
		v[i].ss=v[i-1].ss+p[i-1]*(ld)sin(radian);
		angle-=60;
	//	trace3(v[i].ff,v[i].ss,radian);
	}
	ld totarea=0;
	for(ll i=1;i<=4;i++)
	{
		ld dist1=distance(v[0],v[i]);
		ld dist2=distance(v[0],v[i+1]);
		ld dist3=distance(v[i],v[i+1]);
	//	trace3(dist1,dist2,dist3);
		totarea+=heron(dist1,dist2,dist3);
	//	trace2(totarea,heron(dist1,dist2,dist3));
	}
	ld areatriangle=(ld)sqrt(3)/4;
//	trace1(totarea);
	ld ans=totarea/areatriangle;
	ll ans2=round(ans);
	cout<<ans2;
	return 0;
}