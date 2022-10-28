#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1000;

long double dp[1001][8001];

int32_t main()
{
	int k,q;
	cin>>k>>q;
	for(int i=0;i<=k;i++)
	{
		long double not_obtained=1;
		for(int j=0;j<=8*N;j++)
		{
			if(i==0)
			{
				dp[i][j]=1;
				continue;
			}
			if(j<i)
			{
				dp[i][j]=0;
				if(j>0)
				{
					not_obtained *= (1 - (long double)1/i);
				}
				continue;
			}
			dp[i][j]=dp[i][j-1] + dp[i-1][j-1] * not_obtained;
			if(j>0)
			{
				not_obtained *= (1 - (long double)1/i);
			}
		}
	}
	while(q--)
	{
		long double p;
		cin>>p;
		for(int i=1;i<=8*N;i++)
		{
			if(dp[k][i]*2000>=p)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}