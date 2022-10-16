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

vector<int> gra[200001];
int vals[200001];
int par[200001];
bool diam[200001];
void dfs(int fr, int at, int val, int parent)
{
	if(vals[at]<=val) {
		vals[at]=val;
		par[at]=parent;
	}
	for(int i:gra[at])
		if(i!=fr)
			dfs(at,i,val+1,parent);
}
bool found=0;
void decreaser(int fr, int at, int val, int parent) {
	if(val==vals[parent])
		found=1;
	for(int i:gra[at])
		if(i!=fr&&(!found))
			decreaser(at,i,val+1,parent);
	if(found) {
		vals[at]=val;
		par[at]=parent;
		diam[at]=1;
	}
}
void printer(int fr, int at) {
	for(int i:gra[at])
		if(i!=fr&&(!diam[i]))
			printer(at,i);
	for(int i:gra[at])
		if(i!=fr&&diam[i])
			printer(at,i);
	cout<<at<<" "<<par[at]<<" "<<at<<endl;
}
void solve()
{
	int n,u,v;
	cin>>n;
	for(int i=1; i<n; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1,0,1);
	int maxi=1;
	for(int i=1; i<=n; i++)
		if(vals[maxi]<vals[i])
			maxi=i;
	dfs(maxi,maxi,0,maxi);
	for(int i=1; i<=n; i++)
		if(vals[maxi]<vals[i])
			maxi=i;
	dfs(maxi,maxi,0,maxi);
	decreaser(maxi, maxi, 0, maxi);
	int ans=0;
	for(int i=1; i<=n; i++)
		ans+=vals[i];
	cout<<ans<<endl;
	for(int i:gra[maxi])
		printer(maxi,i);
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