/*
 * 	i could never find the right way to tell you
 * 		have you noticed i've been gone?
 * 			cause i left behind the home that you made me
 * 				but i will carry it along
 * 	mm it's a long way forward
 * 		so trust in me
 * 			i'll give them shelter like you've done for me
 * 				and i know i'm not alone
 * 					you'll be watching over us
 * 						until you're gone
 * 	when i'm older i'll be silent beside you
 * 		I know that words are not enough
 * 			and they won't need to know our names or our faces
 * 				but they will carry on for us
 */

#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=1e18;
const int infi=2e9;
const int mod=998244353;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int N=1e5+5;
vector<pii> gra[N];
vector<pair<int,pii>> edges;
vector<pii> tree[N];
int par[N];
int addit[21][N];
int fpar(int i) {
	return par[i]<0?i:par[i]=fpar(par[i]);
}
bool merge(int u, int v) {
	if((u=fpar(u))!=(v=fpar(v))) {
		if(par[u]>par[v])
			swap(u,v);
		par[u]+=par[v];
		par[v]=u;
		return 1;
	}
	return 0;
}
vi additional;
bool lol[N];
int dp[18][N];
int dist[18][N];
int depth[N];
void dfs(int fr, int at) {
	depth[at]=depth[fr]+1;
	dp[0][at]=fr;
	for(auto &i:tree[at]) {
		if(i.fi!=fr) {
			dfs(at,i.fi);
			dist[0][i.fi]=i.se;
		}
	}
}
void solve() {
	int n,m,u,v,w,q;
	cin>>n>>m;
	fill(par+1,par+n+1,-1);
	fr(i,1,m) {
		cin>>u>>v>>w;
		edges.pb({w,{u,v}});
		gra[u].pb({v,w});
		gra[v].pb({u,w});
	}
	sort(all(edges));
	for(auto &edge:edges)
		if(merge(edge.se.fi,edge.se.se)) {
			tree[edge.se.fi].pb({edge.se.se,edge.fi});
			tree[edge.se.se].pb({edge.se.fi,edge.fi});
		} else
			additional.pb(edge.se.fi);
	dfs(1,1);
	for(int i=0; i<sz(additional); i++) {
		int te=additional[i];
		fill(addit[i]+1,addit[i]+n+1,infl);
		addit[i][te]=0;
		auto cmp=[i](int u, int v){
			if(addit[i][u]!=addit[i][v])
				return addit[i][u]<addit[i][v];
			return u<v;
		};
		set<int,decltype(cmp)> heap(cmp);
		heap.insert(te);
		while(!heap.empty()) {
			int po=*heap.begin();
			heap.erase(po);
			for(auto &v:gra[po])
				if(addit[i][po]+v.se<addit[i][v.fi]) {
					heap.erase(v.fi);
					addit[i][v.fi]=addit[i][po]+v.se;
					heap.insert(v.fi);
				}
		}
	}
	for(int i=1; i<18; i++)
		for(int j=1; j<=n; j++) {
			dp[i][j]=dp[i-1][dp[i-1][j]];
			dist[i][j]=dist[i-1][j]+dist[i-1][dp[i-1][j]];
		}
	cin>>q;
	while(q--) {
		cin>>u>>v;
		int dist1=infl,dist2=0;
		for(int i=0; i<sz(additional); i++)
			dist1=min(dist1,addit[i][u]+addit[i][v]);
		if(depth[u]<depth[v]) swap(u,v);
		for(int i=17; i>=0; i--)
			if(depth[dp[i][u]]>=depth[v]) {
				dist2+=dist[i][u];
				u=dp[i][u];
			}
		if(u!=v) {
			for(int i=17; i>=0; i--)
				if(dp[i][u]!=dp[i][v]) {
					dist2+=dist[i][u]+dist[i][v];
					u=dp[i][u];
					v=dp[i][v];
				}
			dist2+=dist[0][u]+dist[0][v];
		}
		cout<<min(dist1,dist2)<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/