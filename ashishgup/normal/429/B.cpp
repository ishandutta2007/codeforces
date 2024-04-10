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

const int N=1e3+5;

int n, m;
ll a[N][N];
ll dp1[N][N]; //Going from 1,1 to i,j
ll dp2[N][N]; //Going from i,j to n,m
ll dp3[N][N]; //Going from n,1 to i,j
ll dp4[N][N]; //Going from i,j to 1,m


int main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp1[i][j]=a[i][j] + max(dp1[i-1][j], dp1[i][j-1]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			dp2[i][j]=a[i][j] + max(dp2[i+1][j], dp2[i][j+1]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			dp3[i][j]=a[i][j] + max(dp3[i+1][j], dp3[i][j-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp4[i][j]=a[i][j] + max(dp4[i-1][j], dp4[i][j+1]);
		}
	}
	ll ans=0;
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			ans=max(ans, dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j]);
			ans=max(ans, dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1]);
		}
	}
	cout<<ans;
	return 0;
}