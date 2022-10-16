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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);
ll powm(ll a,ll b) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a);
		a=(a*a);
		b>>=1;
	}
	return te;
}
vector<int> gra[200001];
int alice[200001],bob[200001];
void dfs(int *a, int fr, int at, int val)
{
	a[at]=val;
	for(int i:gra[at])
		if(i!=fr)
			dfs(a,at,i,val+1);
}
void solve()
{
	int n,x,u,v;
	cin>>n>>x;
	for(int i=1; i<n; i++)
		cin>>u>>v,gra[u].pb(v),gra[v].pb(u);
	dfs(alice,1,1,0);
	dfs(bob,x,x,0);
	int ans=0;
	for(int i=1; i<=n; i++)
		if(alice[i]>bob[i])
			ans=max(ans,alice[i]);
	cout<<(ans*2)<<endl;
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
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
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