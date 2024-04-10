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

const int N=1e3+5;

ll n;
long double cache[N][N][2];
int vis[N][N][2];

long double dp(ll w, ll b, ll chance)
{
	if(vis[w][b][chance])
	{
		return cache[w][b][chance];
	}
	vis[w][b][chance]=1;
	if(!chance)
	{
		if(w==0)
		{
			cache[w][b][chance]=0;
			return cache[w][b][chance];
		}
		if(b==0)
		{
			cache[w][b][chance]=1;
			return cache[w][b][chance];
		}
		ld win=(ld)(w)/(b+w);
		ld lose=(ld)(b)/(b+w);
		ld next=dp(w,b-1,1);
		lose*=next;
		cache[w][b][chance]=win+lose;
		return cache[w][b][chance];
	}
	else
	{
		if(b==0)
		{
			cache[w][b][chance]=0;
			return cache[w][b][chance];
		}
		if(w+b==1)
		{
			cache[w][b][chance]=0;
			return cache[w][b][chance];
		}
		if(w+b==2)
		{
			cache[w][b][chance]=0;
			return cache[w][b][chance];
		}
		ld win=(ld)(b)/(w+b);
		if(b==1&&w>0)
		{
			win*=dp(w-1,b-1,0);
			cache[w][b][chance]=win;
			return cache[w][b][chance];
		}
		else if(b>1 && w>0)
		{
			ld store1=dp(w-1,b-1,0);
			ld store2=dp(w,b-2,0);
			store1*=(ld)(w)/(w+b-1);
			store2*=(ld)(b-1)/(w+b-1);
			win*=(store1+store2);
			cache[w][b][chance]=win;
			return cache[w][b][chance]=win;
		}
	}
	return cache[w][b][chance]; 
}

int main()
{
	IOS;
	ll w,b;
	cin>>w>>b;
	ld ans=dp(w,b,0);
	cout<<fixed<<setprecision(10)<<ans;
	return 0;
}