#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
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

int dp1[500005],dp2[500005];
vector<pii> gra[500005];
int k;
void dfs(int fr, int at) {
	vi sat,unsat;
	for(auto i:gra[at]) {
		if(i.fi!=fr) {
			dfs(at,i.fi);
			sat.pb(dp1[i.fi]);
			unsat.pb(dp2[i.fi]+i.se-dp1[i.fi]);
		}
	}
	sort(all(unsat));
	reverse(all(unsat));
	int sum=accumulate(all(sat),0LL),sum2=0;
	for(int j=0; j+1<k&&j<sz(unsat); j++)
		sum2+=max(0LL,unsat[j]);
	dp2[at]=sum+sum2;
	if(k<=sz(unsat)&&unsat[k-1]>=0)
		sum2+=unsat[k-1];
	dp1[at]=sum+sum2;
}
void solve() {
	int n;
	cin>>n>>k;
	memset(dp1,0,sizeof(int)*(n+4));
	memset(dp2,0,sizeof(int)*(n+4));
	fr(i,1,n)
		gra[i].clear();
	fr(i,2,n) {
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].pb({v,w});
		gra[v].pb({u,w});
	}
	dfs(1,1);
	cout<<max(dp1[1],dp2[1])<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t) {
//		cout<<"Case "<<i<<": ";
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}