/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I don't know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

const int N=2e5+5;
vector<pii> gra[N];
int dsu[N],depth[N];
int dp[20][N],dp2[20][N];
int par(int i) {
	return dsu[i]<0?i:dsu[i]=par(dsu[i]);
}
bool merge(int i, int j) {
	if((i=par(i))!=(j=par(j))) {
		if(dsu[i]>dsu[j]) swap(i,j);
		dsu[i]+=dsu[j];
		dsu[j]=i;
		return 1;
	}
	return 0;
}
void dfs(int fr, int at, int lev) {
	dp[0][at]=fr;
	depth[at]=lev;
	for(auto i:gra[at]) {
		if(i.fi!=fr) {
			dp2[0][i.fi]=i.se;
			dfs(at,i.fi,lev+1);
		}
	}
}
bool used[N];
int anses[N];
void solve() {
	int n,m,u,v,w;
	cin>>n>>m;
	vector<pair<pii,pii>> edges;
	int weight=0;
	fr(i,1,m) {
		cin>>u>>v>>w;
		edges.pb({{w,i},{u,v}});
	}
	int ii=0;
	fill(dsu+1,dsu+n+1,-1);
	sort(all(edges));
	for(auto &e:edges) {
		if(merge(e.se.fi,e.se.se)) {
			used[ii]=1;
			trace(e.fi.se);
			weight+=e.fi.fi;
			gra[e.se.fi].pb({e.se.se,e.fi.fi});
			gra[e.se.se].pb({e.se.fi,e.fi.fi});
		}
		ii++;
	}
	trace(ii);
	dfs(1,1,0);
	trace(ii);
	for(int i=1; i<20; i++)
		for(int j=1; j<=n; j++) {
			dp[i][j]=dp[i-1][dp[i-1][j]];
			dp2[i][j]=max(dp2[i-1][dp[i-1][j]],dp2[i-1][j]);
		}
	trace(ii);
	ii=0;
	for(auto &e:edges) {
		trace(ii);
		if(used[ii]) {
			anses[e.fi.se]=weight;
			ii++;
			continue;
		}
		ii++;
		int u=e.se.fi,v=e.se.se;
		int ans=0;
		if(depth[u]<depth[v]) swap(u,v);
		for(int i=19; i>=0; i--)
			if(depth[dp[i][u]]>=depth[v]) {
				ans=max(ans,dp2[i][u]);
				u=dp[i][u];
			}
		if(u==v) {
			trace(ans,e.fi.fi,e.fi.se);
			anses[e.fi.se]=weight+e.fi.fi-ans;
			continue;
		}
		for(int i=19; i>=0; i--) {
			if(dp[i][u]!=dp[i][v]) {
				ans=max(ans,dp2[i][u]);
				ans=max(ans,dp2[i][v]);
				u=dp[i][u],v=dp[i][v];
			}
		}
		ans=max(ans,dp2[0][u]);
		ans=max(ans,dp2[0][v]);
		trace(ans,e.fi.fi,e.fi.se);
		anses[e.fi.se]=weight+e.fi.fi-ans;
	}
	fr(i,1,m) {
		cout<<anses[i]<<endl;
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
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}