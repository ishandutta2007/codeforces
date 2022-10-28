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
typedef vector<long long> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const long long N=2e5+5;

ll r,g,h;
ll dp[2][N];

bool check(ll k)
{
	ll storer=r,storeg=g;
	while(k>0&&(storer>=k || storeg>=k))
	{
		if(storer>=storeg)
		{
			storer-=k;
		}
		else
		{
			storeg-=k;
		}
		k--;
	}
	if(k==0)
		return true;
	else
		return false;
}

ll binsearch(ll lo,ll hi)
{
	while(lo<hi)
	{
		ll mid=(lo+hi+1) >> 1;
		if(check(mid))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	return lo;
}

ll getg(ll curh, ll curr)
{
	ll usedblocks=(curh)*(curh+1)/2;
	return g-(usedblocks - curr);
} 
int main()
{
	IOS;
	cin>>r>>g;
	h=binsearch(0,1e4);
	for(int i=0;i<=h-1;i++)
	{
		for(int j=0;j<=r;j++)
		{
			if(i==0&&j==0)
			{
				dp[i&1][j]=1;
			}
			dp[i&1][j]%=MOD;
			int remr=(r-j);
			int remg=getg(i,j);
			if(remr>=i+1)
			{
				dp[!(i&1)][j+i+1]+=dp[i&1][j];
			}
			if(remg>=i+1)
			{
				dp[!(i&1)][j]+=dp[i&1][j];
			}
			dp[i&1][j]=0;
		}
	}
	ll answer=0;
	for(int i=0;i<=r;i++)
	{
		answer+=dp[h&1][i];
	}
	answer%=MOD;
	cout<<answer;
	return 0;
}