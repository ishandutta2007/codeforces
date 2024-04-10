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

const int N=1e2+5;
const int M=1e4+5;

int n, m;
int a[N][N], pref[N][N], suf[N][N], calc[N][N], cache[N][M], vis[N][M];

int dp(int i, int tobreak)
{
	if(i>n)
	{
		if(tobreak==0)
			return 0;
		return INT_MIN;
	}
	if(vis[i][tobreak])
		return cache[i][tobreak];
	vis[i][tobreak]=1;
	int ans=0;
	for(int j=min(tobreak, a[i][0]);j>=0;j--)
	{
		ans=max(ans, calc[i][j] + dp(i+1, tobreak-j));
	}
	cache[i][tobreak]=ans;
	return ans;
}

int main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		a[i][0]=num;
		for(int j=1;j<=num;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int num=a[i][0];
		for(int j=1;j<=num;j++)
		{
			pref[i][j]=pref[i][j-1] + a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int num=a[i][0];
		for(int j=num;j>=1;j--)
		{
			suf[i][j]=suf[i][j+1] + a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int num=a[i][0];
		for(int j=0;j<=num;j++)
		{
			calc[i][j]=0;
			for(int k=0;k<=j;k++)
			{
				int prefvalue=pref[i][k];
				int sufvalue=suf[i][num+1-(j-k)];
				calc[i][j]=max(calc[i][j], prefvalue + sufvalue);
			}
		}
	}
	cout<<dp(1, m);
	return 0;
}