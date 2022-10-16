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
typedef float f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
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


int dsu[100005];
int fpar(int i) {
	return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
bool merge(int i, int j) {
	if((i=fpar(i))!=(j=fpar(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		dsu[i]+=dsu[j];
		dsu[j]=i;
		return 1;
	}
	return 0;
}
vector<pii> gra[100005];
int dp[18][100005],dp2[18][100005],depth[100005];
void dfs(int fr, int at,int deep) {
	dp[0][at]=fr;
	depth[at]=deep;
	for(auto i:gra[at]) {
		if(i.fi!=fr) {
			dfs(at,i.fi,deep+1);
			dp2[0][i.fi]=i.se;
		}
	}
}
void solve() {
	memset(dsu,-1,sizeof(dsu));
	int n,m;
	cin>>n>>m;
	vector<pair<pii,pii>> edges;
	fr(i,1,m) {
		int u,v,w;
		cin>>u>>v>>w;
		edges.pb({{w,i},{u,v}});
	}
	sort(all(edges));
	vector<pair<pii,pii>> nonspan;
	for(auto e:edges) {
		if(merge(e.se.fi,e.se.se)) {
			gra[e.se.fi].pb({e.se.se,e.fi.fi});
			gra[e.se.se].pb({e.se.fi,e.fi.fi});
		}
		else
			nonspan.pb(e);
	}
	dfs(1,1,1);
	for(int i=1; i<18; i++)
		fr(j,1,n) {
			dp[i][j]=dp[i-1][dp[i-1][j]];
			dp2[i][j]=max(dp2[i-1][j],dp2[i-1][dp[i-1][j]]);
		}
	vector<pii> ans;
	for(auto e:nonspan) {
		int u=e.se.fi,v=e.se.se;
		int val=0;
		if(depth[u]<depth[v])
			swap(u,v);
		for(int i=17; i>=0; i--) {
			if(depth[dp[i][u]]>=depth[v]) {
				val=max(val,dp2[i][u]);
				u=dp[i][u];
			}
		}
		if(u!=v) {
			for(int i=17; i>=0; i--) {
				if(dp[i][u]!=dp[i][v]) {
					val=max(val,max(dp2[i][u],dp2[i][v]));
					u=dp[i][u];
					v=dp[i][v];
				}
			}
			val=max(val,max(dp2[0][u],dp2[0][v]));
		}
		ans.pb({e.fi.se,val});
	}
	sort(all(ans));
	for(auto i:ans)
		cout<<i.se<<" ";
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