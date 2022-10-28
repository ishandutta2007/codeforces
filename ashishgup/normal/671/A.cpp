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
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const long long N=1e5+5;

long double ax, ay, bx, by, cx, cy;
long long n;
pair<long double, long double> v[N];
long double d[N];
long double cache[N][2][2];
int vis[N][2][2];

long double distance(ld x1, ld y1, ld x2, ld y2)
{
	ld xdiff=(x2-x1)*(x2-x1);
	ld ydiff=(y2-y1)*(y2-y1);
	ld total=xdiff+ydiff;
	total=(ld)sqrt(total);
	return total;
}

long double dp(int i, int check1, int check2)
{
	if(i>=n)
	{
		if(check1 || check2)
		{
			return 0;
		}
		return 1e13;
	}
	if(vis[i][check1][check2])
	{
		return cache[i][check1][check2];
	}
	vis[i][check1][check2]=1;
	long double pos1=2*d[i]+dp(i+1, check1, check2);
	long double pos2=LLONG_MAX;
	long double pos3=LLONG_MAX;
	if(!check1)
	{
		pos2=d[i] + distance(ax, ay, v[i].ff, v[i].ss) + dp(i+1, 1, check2);
	}
	if(!check2)
	{
		pos3=d[i] + distance(bx, by, v[i].ff, v[i].ss) + dp(i+1, check1, 1);
	}
	cache[i][check1][check2]=Min(pos1, pos2, pos3);
	return cache[i][check1][check2];
}
int main()
{ 
	IOS;
	cin>>ax>>ay>>bx>>by>>cx>>cy;	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v[i].ff>>v[i].ss;
	}
	for(int i=0;i<n;i++)
	{
		d[i]=distance(v[i].ff, v[i].ss, cx, cy);
	}
	cout<<fixed<<setprecision(12)<<dp(0,0,0);
	return 0;
}