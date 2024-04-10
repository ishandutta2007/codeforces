#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=4005;
const int M1=805;

int n, k, distinct=0, l = 1, r = 0, current_val=0; 
int a[N][N], cost[N][N];
int dp[M1][N], P[M1][N];

int get_cost(int i, int j)
{
	int store=(cost[j][j]-cost[i-1][j]-cost[j][i-1]+cost[i-1][i-1]) >> 1;
	return store;
}

void conquer(int g, int L, int R, int lo, int hi)
{
	if(L>R)
		return;
	int M=(L+R)>>1;
	int bestk=0;
	dp[g][M]=1e9;
	for(int k1=lo;k1<=min(hi, M);k1++)
	{
		int cur_cost=dp[g-1][k1-1]+get_cost(k1, M);
		if(cur_cost<=dp[g][M])
		{
			dp[g][M]=cur_cost;
			bestk=k1;
		}
	} 
	P[g][M]=bestk;
	if(L!=R)
	{
		conquer(g, L, M-1, lo, bestk);
		conquer(g, M+1, R, bestk, hi);
	}
}

int32_t main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char ch='#';
			while(!isdigit(ch))
				ch=getchar();
			a[i][j]=ch-'0';
			cost[i][j]=a[i][j];
			cost[i][j]+=cost[i][j-1];

		}
		dp[0][i]=1e9;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			cost[j][i]+=cost[j-1][i];
		}
	}
	for(int i=1;i<=k;i++)
	{
		conquer(i, 1, n, 1, n);
	}
	cout<<dp[k][n];
	return 0;
}