//#define opti
#ifdef opti
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

bool a[101],b[101];
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<=100; i++)
		a[i]=1;
	for(int i=1; i<=n; i++)
	{
		int te;
		cin>>te;
		for(int j=1; j<=te; j++)
		{
			int p;
			cin>>p;
			b[p]=1;
		}
		for(int j=1; j<=100; j++)
		{
			if(!b[j])
				a[j]=0;
			b[j]=0;
		}
	}
	for(int i=1; i<=100; i++)
		if(a[i])
			cout<<i<<" ";
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	clock_t clk = clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	clk = clock() - clk;
	fflush(stdout);
	cerr<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
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