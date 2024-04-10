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
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5 + 5;

int n,m;
ll h[N],p[N];

bool check(ll t)
{
	ll u=0;
	for(ll i=0;i<n;i++)
	{
		ll left=h[i]-p[u];
		left=max(0LL,left);
		if(t<left)
		{
			return 0;
		}
		ll right=t-2*left;
		right=max(right,0LL);
		right=max(right,(t-left)/2);
		while(u<m&&(p[u]<=(h[i]+right)))
		{
			u++;
		}
		if(u==m)
		{
			return 1;
		}
	}
	return 0;
}	
ll binsearch(ll lo, ll hi)
{
	while(lo<hi)
	{
		ll mid=(lo+hi)>>1;
		if(check(mid))
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	return lo;
}
int main()
{
	IOS;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>p[i];
	}
	ll ans=binsearch(0,1e15);
	cout<<ans;
	return 0;
}