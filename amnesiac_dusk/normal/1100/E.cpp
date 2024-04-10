/*
 * RD
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//12367769,266916112,123798211
ll powm(ll a, ll b, ll m);

vector<int> gra[100005];
int vis[100005];
vector<pair<pii,pii>> edges;
bool cycle;
void dfs(int at, int fromer)
{
	vis[at]=1;
	for(int i:gra[at])
		if(vis[i]==1)
			cycle=1;
		else if(vis[i]==0)
			dfs(i,fromer);
	vis[at]=2;
}
stack<int> topo;
void dfs(int at)
{
	vis[at]=1;
	for(int i:gra[at])
		if(!vis[i])
			dfs(i);
	topo.push(at);
}
int topological[100005];
void solve()
{
	int n,m,u,v,c;
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>u>>v>>c;
		edges.pb({{c,i},{u,v}});
	}
//	sort(all(edges));
//	reverse(all(edges));
	int lo=0,hi=1e9,mi=(lo+hi)/2;
	while(lo<hi)
	{
		for(int i=1; i<=n; i++)
			gra[i].clear();
		fill(vis+1,vis+n+1,0);
		for(int i=0; i<m; i++)
			if(edges[i].fi.fi>mi)
				gra[edges[i].se.fi].pb(edges[i].se.se);
		cycle=0;
		for(int i=1; i<=n; i++)
			if(!vis[i])
				dfs(i,i);
		if(cycle)
			lo=mi+1;
		else
			hi=mi;
		mi=(lo+hi)/2;
	}
	for(int i=1; i<=n; i++)
		gra[i].clear();
	fill(vis+1,vis+n+1,0);
	for(int i=0; i<m; i++)
		if(edges[i].fi.fi>mi)
			gra[edges[i].se.fi].pb(edges[i].se.se);
	int ind=1;
	for(int i=1; i<=n; i++)
		if(!vis[i])
			dfs(i);
	while(!topo.empty())
	{
		topological[topo.top()]=ind;
		topo.pop();
		ind++;
	}
	int ans1=mi,ans2=0;
	for(int i=0; i<m; i++)
		if(edges[i].fi.fi<=mi)
			if(topological[edges[i].se.fi]>topological[edges[i].se.se])
				ans2++;
	cout<<ans1<<" "<<ans2<<endl;
	for(int i=0; i<m; i++)
		if(edges[i].fi.fi<=mi)
			if(topological[edges[i].se.fi]>topological[edges[i].se.se])
				cout<<edges[i].fi.se<<" ";
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
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