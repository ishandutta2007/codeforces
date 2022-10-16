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

vector<int> gra[100001];
int vals[100001];
int dfs(int fr, int at)
{
	vals[at]=0;
	int b=1;
	for(int i:gra[at])
		if(i!=fr)
		{
			vals[at]+=dfs(at,i);
			b=0;
		}
	vals[at]+=b;
	return vals[at];
}
void solve()
{
	int n,p;
	cin>>n;
	for(int i=2; i<=n; i++)
	{
		cin>>p;
		gra[p].pb(i);
		gra[i].pb(p);
	}
	dfs(1,1);
	sort(vals+1,vals+n+1);
	for(int i=1; i<=n; i++)
		cout<<vals[i]<<" ";
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