/*
 * :(
 * You taught me so much, I'm not scared anymore
 * 	I have to left go your hands that are holding me
 * 	 Even if I'm alone, I'll go on, even if it hurts
 * 	  I'll never forget the dream, I shared with you
 * 	   I'm glad to be with everyone, I'm glad to have been with everyone
 * 	    But on the morning when I wake up, no one is there
 */
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
#define deb cout<<"Line: "<<__LINE__<<" pls "
typedef long long ll;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

vector<int> gra[100001];
int lev[100001];
void dfs(int fr, int at, int level)
{
	lev[level]++;
	for(int i:gra[at])
		if(i!=fr)
			dfs(at,i,level+1);
}
void solve()
{
	int n,k,p;
	cin>>n>>k>>p;
	for(int i=1,u,v; i<n; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1,1);
	int cost=0,val=0;
	int ans=0;
	for(int i=100000,j=100000; i>1;)
	{
		while(cost+lev[i]*(j-i)<=p&&i>1)
		{
			cost+=lev[i]*(j-i);
			val+=lev[i];
			i--;
		}
		if(i>1)
			ans=max(ans,val+((p-cost)/(j-i)));
		else
			ans=max(ans,val);
		val-=lev[j];
		cost-=val;
		j--;
	}
	cout<<min(ans,k)<<endl;
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