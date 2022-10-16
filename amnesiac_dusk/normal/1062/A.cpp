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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


void solve()
{
	int n;
	cin>>n;
	vector<int> a;
	int te;
	for(int i=1; i<=n; i++)
	{
		cin>>te;
		a.pb(te);
	}
	int ans=0;
	if(a[0]==1)
	{
		for(int j=1; j<n; j++)
		{
			if(a[j]!=j+1)
			{
				ans=j-1;
				break;
			}
			if(j==n-1)
				ans=n-1;
		}
	}
	if(a[n-1]==1000)
		for(int i=n-2; i>=0; i--)
		{
			if(a[i]!=1000+i-n+1)
			{
				ans=max(ans,n-i-2);
				break;
			}
			if(i==0)
				ans=n-1;
		}
	te=0;
	for(int i=1; i<n; i++)
	{
		if(a[i]==a[i-1]+1)
			te++;
		else
			te=0;
		ans=max(ans,te-1);
	}
	cout<<ans<<endl;
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