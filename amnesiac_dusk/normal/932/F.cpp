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
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
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
typedef float f80;
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
/**
 * Description: Given set of lines, computes the greatest y-coordinate(minmax=0) or smallest y-coordinate(minmax=1) for any x
 * Source: KACTL
 * Verification: CSA Squared Ends
 */
bool Q;
struct Line {
	mutable ll k, m, p;//slope, y-intercept, last optimal x
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<Line> {
	const bool minmax;
	LineContainer(bool minmax):minmax(minmax) {
	}
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
	    if (b < 0) a *= -1, b *= -1;
	    if (a >= 0) return a/b;
	    return -((-a+b-1)/b);
	}

	// updates x->p, determines if y is unneeded
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return 0; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}

	void add(ll k, ll m) {
		if(minmax)
			k*=-1,m*=-1;
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}

	ll query(ll x) {
		assert(!empty());
		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
		return (minmax?-1:1)*(l.k * x + l.m);
	}
};
LineContainer cht(1);
const int N=1e5+5;
int ans[N],a[N],b[N],sz[N],maxi[N];
vi gra[N];
vi order;
int in[N],out[N];
int cntr=0;
void dfs(int fr, int at) {
	sz[at]=1;
	maxi[at]=0;
	order.pb(at);
	in[at]=cntr++;
	for(int i:gra[at])
		if(i!=fr) {
			dfs(at,i);
			sz[at]+=sz[i];
			if(sz[i]>sz[maxi[at]])
				maxi[at]=i;
		}
	out[at]=cntr;
}
void dfs(int fr, int at, int keep) {
	for(int i:gra[at])
		if(i!=fr)
			if(i!=maxi[at])
				dfs(at,i,0);
	if(maxi[at])
		dfs(at,maxi[at],1);
	for(int i:gra[at])
		if(i!=fr)
			if(i!=maxi[at])
				for(int j=in[i]; j<out[i]; j++)
					cht.add(b[order[j]],ans[order[j]]);
	if(maxi[at]==0)
		ans[at]=0;
	if(ans[at]==-1)
		ans[at]=cht.query(a[at]);
	cht.add(b[at], ans[at]);
	if(keep==0)
		cht.clear();
}
void solve() {
	memset(ans,-1,sizeof(ans));
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	fr(i,1,n)
		cin>>b[i];
	fr(i,2,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1);
	dfs(1,1,0);
	fr(i,1,n)
		cout<<ans[i]<<" ";
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}