//#define opti
#ifdef opti
#define min(x, y) (y ^ ((x ^ y) & -(x < y)))
#define max(x, y) (x ^ ((x ^ y) & -(x < y)))
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif
#ifndef opti
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int dp[55][1005][1005];
ll dp2[55][1005];
ll ans[55][1005];
ll fact[55];
void solve()
{
	dp[1][0][0]=1;
	for(int i=1; i<=50; i++)
		for(int j=0; j<=1000; j++)
			for(int k=0; k<=1000; k++)
			{
				dp[i][j+1][k+1]=(dp[i][j+1][k+1]+dp[i][j][k])%mod;
				if(k+j+1<=1000)
					dp[i+1][j+1][k+j+1]=(dp[i+1][j+1][k+j+1]+dp[i][j][k])%mod;
			}
	dp2[1][1]=1;
	for(int i=1; i<=50; i++)
		for(int j=1; j<=1000; j++)
		{
			dp2[i][j+1]=(dp2[i][j+1]+dp2[i][j])%mod;
			dp2[i+1][j+1]=(dp2[i+1][j+1]+dp2[i][j])%mod;
		}
	for(int i=1; i<=50; i++)
		for(int j=0; j<=1000; j++)
			for(int k=0; k<=1000; k++)
				dp[i][j+1][k]=(dp[i][j+1][k]+dp[i][j][k])%mod;
	for(int i=1; i<=50; i++)
		for(int j=0; j<=1000; j++)
			for(int k=0; k<=1000-j; k++)
				ans[i][j+k]=(ans[i][j+k]+dp[i][1000][j]*dp2[i][k])%mod;
	fact[0]=1;
	for(int i=1; i<=50; i++)
		fact[i]=(fact[i-1]*i)%mod;
	for(int i=1; i<=50; i++)
		for(int j=1; j<=1000; j++)
			ans[i][j]=(ans[i][j-1]+ans[i][j]*fact[i])%mod;
	int q;
	cin>>q;
	while(q--)
	{
		int n,k;
		cin>>n>>k;
		if(k>50)
			cout<<0<<endl;
		else
			cout<<ans[k][n]<<endl;
	}
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifdef rd
		clock_t clk = clock();
	#endif
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	#ifdef rd
		clk = clock() - clk;
		cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
	#endif
	return 0;
}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}