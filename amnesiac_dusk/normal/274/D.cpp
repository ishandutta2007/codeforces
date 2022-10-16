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

vector<vector<pii>> a;
vector<int> gra[300001];
bool indfs[300001];
bool vis[300001];
vector<int> topo;
void dfs(int at)
{
	indfs[at]=1;
	vis[at]=1;
	for(int i:gra[at])
	{
		if(indfs[i])
		{
			cout<<-1<<endl;
			exit(0);
		}
		if(!vis[i])
			dfs(i);
	}
	topo.pb(at);
	indfs[at]=0;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	a.pb(vector<pii>());
	for(int i=0; i<n; i++)
		a.pb(vector<pii>(m+1));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			cin>>a[i][j].fi;
			a[i][j].se=j;
		}
	int pseudo=100001;
	vector<int>cur;
	for(int i=1; i<=n; i++)
	{
		pseudo++;
		sort(a[i].begin()+1,a[i].end());
		for(int j=1; j<=m; j++)
		{
			if(a[i][j].fi!=-1)
			{
				if(a[i][j].fi==a[i][j-1].fi)
					cur.pb(a[i][j].se);
				else
				{
					for(int k:cur)
						gra[pseudo].pb(k);
					pseudo++;
					for(int k:cur)
						gra[k].pb(pseudo);
					cur.clear();
					cur.pb(a[i][j].se);
				}
			}
		}
		for(int k:cur)
			gra[pseudo].pb(k);
		cur.clear();
	}
	for(int i=1; i<=m; i++)
		if(!vis[i])
			dfs(i);
	reverse(all(topo));
	for(int i:topo)
		if(i<=100000)
			cout<<i<<" ";
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