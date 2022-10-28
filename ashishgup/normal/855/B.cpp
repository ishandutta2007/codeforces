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
typedef pair<long long, long long> pll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;

ll a[N];
ll n,p,q,r;
ll cache[N][2][2][2];
int vis[N][2][2][2];

ll dp(ll i, int ch1, int ch2, int ch3)
{
	if(i>n)
	{
		if(!ch1 || !ch2 || !ch3)
			return -4e18;
		return 0;
	}	
	if(vis[i][ch1][ch2][ch3])
	{
		return cache[i][ch1][ch2][ch3];
	}
	vis[i][ch1][ch2][ch3]=1;
	cache[i][ch1][ch2][ch3]=dp(i+1, ch1, ch2, ch3);
	if(ch1==0)
	{
		cache[i][ch1][ch2][ch3]=max(cache[i][ch1][ch2][ch3], p*a[i] + dp(i, 1, ch2, ch3));
	}
	if((ch1==1)&&(ch2==0))
	{
		cache[i][ch1][ch2][ch3]=max(cache[i][ch1][ch2][ch3], q*a[i] + dp(i, 1, 1, ch3));
	}
	if((ch1==1)&&(ch2==1)&&(ch3==0))
	{
		cache[i][ch1][ch2][ch3]=max(cache[i][ch1][ch2][ch3], r*a[i] + dp(i, 1, 1, 1));
	}
	return cache[i][ch1][ch2][ch3];
}
int main()
{
	IOS;
	cin>>n>>p>>q>>r;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<dp(1, 0, 0, 0);
	return 0;
}