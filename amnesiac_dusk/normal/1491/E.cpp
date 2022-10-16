#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
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
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

vi gra[200005];
int dp[200005];
vi fib={1,1};
int sz[200005];
bool disabled[200005];
int par[200005];
void dfs(int fr, int at) {
	par[at]=fr;
	sz[at]=1;
	for(int i:gra[at]) {
		if(i!=fr&&disabled[i]==0) {
			dfs(at,i);
			sz[at]+=sz[i];
		}
	}
}
void dfs2(int fr, int at, vi &pp) {
	pp.pb(at);
	for(int i:gra[at]) {
		if(i!=fr&&disabled[i]==0) {
			dfs2(at,i,pp);
		}
	}
}
void check(vi at, int num) {
	if(sz(at)<=2)
		return;
	for(int i:at)
		sz[i]=0;
	dfs(at[0],at[0]);
	for(int i:at) {
		if(sz[i]==fib[num-1]) {
			vi get1;
			disabled[i]=1;
			dfs2(at[0],at[0],get1);
			check(get1,num-2);
			get1.clear();
			disabled[i]=0;

			disabled[par[i]]=1;
			dfs2(i,i,get1);
			check(get1,num-1);
			disabled[par[i]]=0;
			return;
		} else if(sz[i]==fib[num-2]) {
			vi get1;
			disabled[i]=1;
			dfs2(at[0],at[0],get1);
			check(get1,num-1);
			disabled[i]=0;
			get1.clear();

			disabled[par[i]]=1;
			dfs2(i,i,get1);
			check(get1,num-2);
			disabled[par[i]]=0;
			return;
		}
	}
	cout<<"NO"<<endl;
	exit(0);
}
void solve() {
	for(int i=2; i<27; i++)
		fib.pb(fib[sz(fib)-1]+fib[sz(fib)-2]);
	int n;
	cin>>n;
	rep(i,1,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	vi a(n);
	iota(all(a),1LL);
	for(int i=0; i<sz(fib); i++) {
		if(n==fib[i]) {
			check(a,i);
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}