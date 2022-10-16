/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
//#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
//#define int long long
//#define double long double
#define fr(a,b,c) for(int a=b; a<=c; a++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);
double dp[301][3001],dp2[301][3001];
double a[3001][301];
double knap1[3001],knap2[3001];
double optilimi[301];
int limi[301];
signed main()
{
//	IO;
	int n,m;
	scanf("%d %d",&n,&m);
	int te;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			scanf("%d",&te);
			a[i][j]=te/1000.0;
			optilimi[j]+=a[i][j];
		}
	for(int i=1; i<=m; ++i)
	{
		optilimi[i]+=5;
		limi[i]=min((int)optilimi[i],n);
	}
	for(int i=1; i<=m; ++i)
	{
		dp[i][0]=1;
		for(int j=1; j<=n; ++j)
			if(a[j][i])
			{
				for(int k=j; k; --k)
					dp[i][k]=dp[i][k]*(1-a[j][i])+dp[i][k-1]*a[j][i];
				dp[i][0]=dp[i][0]*(1-a[j][i]);
			}
	}
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j)
		{
			for(int k=1; k<j; ++k)
				dp2[i][k]+=dp[i][j]*k;
			for(int k=j; k<=n; ++k)
				dp2[i][k]+=dp[i][j]*j;
		}
	for(int i=1; i<=m; ++i)
	{
		for(int j=0; j<=limi[i]; ++j)
			for(int k=0; k<=n-j; ++k)
				knap2[k+j]=max(knap2[k+j],knap1[k]+dp2[i][j]);
		for(int j=0; j<=n; ++j) {
			knap1[j]=knap2[j];
			knap2[j]=0;
		}
	}
	printf("%.12f",knap1[n]);
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