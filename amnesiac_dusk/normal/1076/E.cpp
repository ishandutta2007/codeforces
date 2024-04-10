#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
//#define endl '\n'
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
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

const int N=3e5+5;
vi gra[N],levels[N];
int tol[N][2],height[N];
vector<pair<int,pii>> queries[N];
struct segtree {
	vector<int> tr;
	vector<int> lazy;int n;
	segtree(int nn, bool lzy=0) {
		n=nn;
		tr.resize(8*n);
		if(lzy)
			lazy.resize(8*n);
	}
	void update(int nd, int s, int e, int l, int r, int val) {
		if(lazy[nd]) {
			tr[nd]+=lazy[nd];
			if(s!=e) {
				lazy[nd<<1]+=lazy[nd];
				lazy[nd<<1|1]+=lazy[nd];
			}
			lazy[nd]=0;
		}
		if(s>r||e<l)
			return;
		else if(l<=s&&e<=r) {
			tr[nd]+=val;
			if(s!=e) {
				lazy[nd<<1]+=val;
				lazy[nd<<1|1]+=val;
			}
			return;
		}
		int m=(s+e)>>1;
		update(nd<<1,s,m,l,r,val);
		update(nd<<1|1,m+1,e,l,r,val);
		tr[nd]=tr[nd<<1]+tr[nd<<1|1];
	}
	int query(int nd, int s, int e, int l, int r) {
		if(s>r||e<l)
			return 0;
		if(lazy[nd]) {
			tr[nd]+=lazy[nd];
			if(s!=e) {
				lazy[nd<<1]+=lazy[nd];
				lazy[nd<<1|1]+=lazy[nd];
			}
			lazy[nd]=0;
		}
		if(l<=s&&e<=r)
			return tr[nd];
		int m=(s+e)>>1;
		return query(nd<<1,s,m,l,r)+query(nd<<1|1,m+1,e,l,r);
	}
};
int anses[N];
int cntr=0;
void dfs(int fr, int at, int lev) {
	levels[lev].pb(at);
	height[at]=lev;
	tol[at][0]=++cntr;
	for(int i : gra[at])
		if(i!=fr)
			dfs(at,i,lev+1);
	tol[at][1]=cntr;
}
void solve() {
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1,0);
	segtree tourpar(n+5,1);
	int m;
	cin>>m;
	while(m--) {
		int v,d,x;
		cin>>v>>d>>x;
		queries[height[v]].pb({x,{tol[v][0],tol[v][1]}});
		queries[min(n+1,height[v]+d+1)].pb({-x,{tol[v][0],tol[v][1]}});
	}
	for(int i=0; i<=n; i++) {
		trace(i);
		for(auto qu:queries[i]) {
			tourpar.update(1, 1, n, qu.se.fi, qu.se.se, qu.fi);
			trace(qu.se.fi,qu.se.se,qu.fi);
		}
		for(auto verts:levels[i]) {
			anses[verts]=tourpar.query(1, 1, n, tol[verts][0], tol[verts][0]);
			trace(verts,anses[verts]);
		}
	}
	for(int i=1; i<=n; i++)
		cout<<anses[i]<<" ";
	cout<<endl;
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