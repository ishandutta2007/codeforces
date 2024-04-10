#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define forn(i, x, y) for(int i = x; i <= y; i++)
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


vector<pii> gra[200005];
int sz[200005],parw[200005];
void dfs(int fr, int at) {
	sz[at]=1;
	for(auto i:gra[at]) {
		if(i.fi!=fr) {
			parw[i.fi]=i.se;
			dfs(at,i.fi);
			sz[at]+=sz[i.fi];
		}
	}
}
void solve() {
	int n;
	cin>>n;
	fr(i,1,2*n) {
		gra[i].clear();
		sz[i]=0;
	}
	rep(i,1,2*n) {
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].pb({v,w});
		gra[v].pb({u,w});
	}
	dfs(1,1);
	int ans1=0,ans2=0;
	fr(i,2,2*n) {
		if(sz[i]&1)
			ans1+=parw[i];
		ans2+=min(sz[i],2*n-sz[i])*parw[i];
	}
	cout<<ans1<<" "<<ans2<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}