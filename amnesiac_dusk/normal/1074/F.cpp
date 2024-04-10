/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=1e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const int N=2e5+5;
vi gra[N];
int depth[N],dp[19][N],inout[N][2];
int cntr=0;
void dfs(int fr, int at, int deep) {
	inout[at][0]=++cntr;
	dp[0][at]=fr;
	depth[at]=deep;
	for(int i:gra[at])
		if(i!=fr)
			dfs(at,i,deep+1);
	inout[at][1]=cntr;
}
pii tr[4*N];
int lazy[4*N];
void pushdown(int seg) {
	if(lazy[seg]) {
		tr[seg<<1].fi+=lazy[seg];
		tr[seg<<1|1].fi+=lazy[seg];
		lazy[seg<<1]+=lazy[seg];
		lazy[seg<<1|1]+=lazy[seg];
		lazy[seg]=0;
	}
}
void update(int seg, int ll, int rr, int l, int r, int val) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		lazy[seg]+=val;
		tr[seg].fi+=val;
		return;
	}
	pushdown(seg);
	update(seg<<1,ll,(ll+rr)/2,l,r,val);
	update(seg<<1|1,1+(ll+rr)/2,rr,l,r,val);
	if(tr[seg<<1].fi==tr[seg<<1|1].fi) {
		tr[seg].fi=tr[seg<<1].fi;
		tr[seg].se=tr[seg<<1].se+tr[seg<<1|1].se;
	} else {
		tr[seg]=max(tr[seg<<1],tr[seg<<1|1]);
	}
}
int lca(int u, int v) {
	for(int i=18; i>=0; i--)
		if(depth[dp[i][u]]>depth[v])
			u=dp[i][u];
	if(dp[0][u]==v)
		return u;
	return 0;
}
void pushpush(int seg, int l, int r) {
	if(l==r) {
		tr[seg]={0,1};
		return;
	}
	pushpush(seg<<1,l,(l+r)/2);
	pushpush(seg<<1|1,1+(l+r)/2,r);
	tr[seg]={0,r-l+1};
}
set<pii> edges;
void solve() {
	int n,q;
	cin>>n>>q;
	pushpush(1,1,n);
	fr(i,2,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(0,1,1);
	for(int i=1; i<19; i++)
		for(int j=1; j<=n; j++)
			dp[i][j]=dp[i-1][dp[i-1][j]];
	while(q--) {
		int u,v;
		cin>>u>>v;
		if(u<v)
			swap(u,v);
		if(depth[u]<depth[v])
			swap(u,v);
		int tol=1;
		if(edges.find({u,v})!=edges.end()) {
			edges.erase({u,v});
			tol=-1;
		} else
			edges.insert({u,v});
		int lc=lca(u,v);
		if(lc) {
			update(1,1,n,inout[u][0],inout[u][1],tol);
			update(1,1,n,inout[lc][0],inout[lc][1],-1*tol);
		} else {
			update(1,1,n,1,n,-1*tol);
			update(1,1,n,inout[u][0],inout[u][1],tol);
			update(1,1,n,inout[v][0],inout[v][1],tol);
		}
		if(tr[1].fi==0) {
			cout<<tr[1].se<<endl;
		} else
			cout<<0<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}