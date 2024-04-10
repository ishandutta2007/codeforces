//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
const ll infl=4e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int a[200005],done[200005];
// Description:
// B -> stores the nodes in a bcc
// bcc[u] -> which bcc u is in.
// cmpno -> number of bcc's
// to just get bridges call get_bridge
struct BCC {
#define N 200005
	vector<int> tree[N],g[N],B[N];int U[N],V[N],temp[N],bcc[N],ind[N],T,cmpno,m,n;
	bitset<N> vis,bridge;
	vector<int> Q[N];
	void init(int _n) {
		n=_n,cmpno=0,T=0,m=0;
	}
	void reset(int n) {
		fr(i, 1, n)
		{
			g[i].clear(),tree[i].clear(),B[i].clear();
			ind[i]=0;
		}
		bridge.reset();
	}
	int adj(int u, int e) {
		return U[e]==u?V[e]:U[e];
	}
	void addedge(int u, int v) {
		U[m]=u,V[m]=v;
		g[u].pb(m),g[v].pb(m);
		m++;
	}
	void get_bridges() {
		fr(i, 1, n)
			if(!vis[i])
				dfs1(i,-1);
		vis.reset();
	}
	void go() {
		get_bridges();
		fr(i, 1, n)
			if(!vis[i]) {
				cmpno++;
				dfs2(i);
			}
		vis.reset();
	}
	int dfs1(int u, int e) {
		vis[u]=1;
		temp[u]=T++;
		int t=temp[u];
		for(int id : g[u]) {
			int v=adj(u,id);
			if(!vis[v])
				t=min(t,dfs1(v,id));
			else if(id!=e)
				t=min(t,temp[v]);
		}
		if(t==temp[u]&&e!=-1)
			bridge[e]=1;
		return t;
	}
	void dfs2(int u) {
		int cur_cmp=cmpno;
		Q[cur_cmp].pb(u);
		bcc[u]=cur_cmp;
		B[cur_cmp].pb(u);
		vis[u]=1;
		while(Q[cur_cmp].size()!=ind[cur_cmp]) {
			int u=Q[cur_cmp][ind[cur_cmp]];
			ind[cur_cmp]++;
			for(int e : g[u]) {
				int v=adj(u,e);
				if(vis[v])
					continue;
				if(bridge[e]) {
					cmpno++;
					tree[cur_cmp].pb(cmpno);
					tree[cmpno].pb(cur_cmp);
					dfs2(v);
				} else {
					Q[cur_cmp].pb(v);
					vis[v]=1;
					bcc[v]=cur_cmp;
					B[cur_cmp].pb(v);
				}
			}
		}
	}
#undef N
} B;

void solve() {
	int n;
	cin>>n;
	B.init(n);
	fr(i,1,n) {
		cin>>a[i];
		B.addedge(i, a[i]);
	}
	B.go();
	int ans=1;
	fr(i,1,B.cmpno) {
		trace(B.B[i].size());
		if(B.B[i].size()>1)
			ans=(ans*(powm(2,B.B[i].size())-2))%mod;
		else
			ans=(ans*2)%mod;
	}
	cout<<ans<<endl;
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
	fflush(stdout);
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}