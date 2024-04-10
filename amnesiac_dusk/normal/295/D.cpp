/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#else
#define deb cout<<"Line: "<<__LINE__<<" plz "
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

const int N=2005;
int dp[N][N],dp2[N][N];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=2; i<=m; i++)
		dp[1][i]=1;
	for(int i=2; i<=n; i++)
	{
		for(int j=2; j<=m; j++)
			dp[i][j]=(dp[i][j-1]+dp[i-1][j]);
		for(int j=2; j<=m; j++)
			dp[i][j]=(dp[i][j]+dp[i][j-1]);
		for(int j=2; j<=m; j++)
			dp[i][j]=(dp[i][j]+1)%mod;
	}
	int ans=0;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			dp2[i][j]=(dp2[i][j-1]+dp[i][j])%mod;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			dp2[i][j]=(dp2[i][j-1]+dp2[i][j])%mod;
	for(int j=2; j<=m; j++)
	{
		for(int i=1; i<=n; i++)
		{
			int te=dp[i][j]*(m-j+1)+((dp[i][j]*(dp2[n-i][j]-dp[n-i][j]))%mod)*(m-j+1);
//			te+=dp[i][j]*lolsum*(m-j+1);
//			lolsum+=dp[n-i][j];
//			for(int k=2; k<j; k++)
//				te=(te+(dp[n-i][k]*(j-k+1))*dp[i][j]*(m-j+1))%mod;
			ans=(ans+te)%mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC <<endl;
#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}