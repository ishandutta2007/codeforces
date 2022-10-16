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
const ll infl= 0x3f3f3f3f3f3f3f3fLL;
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


vi gra2[100005];
vi gra[100005];
vector<pii> ans;
int mdi=0;
void dfs(int fr, int at) {
	for(int i:gra2[at]) {
		if(i!=fr) {
			gra[at].pb(i);
			dfs(at,i);
		}
	}
}
void dfs(int fr, int at, int ti) {
	int here=ti;
	ans.pb({at,ti});
	for(int i=0; i<sz(gra[at]); i++){
		here++;
		if(here==mdi+1) {
			int pol=ti-sz(gra[at])+i;
			here=pol;
			ans.pb({at,here-1});
		}
		dfs(at,gra[at][i],here);
		ans.pb({at,here});
	}
	if(ans.back().se!=ti-1)
		ans.pb({at,ti-1});
}
void solve() {
	int n;
	cin>>n;
	fr(i,2,n) {
		int u,v;
		cin>>u>>v;
		gra2[u].pb(v);
		gra2[v].pb(u);
	}
	fr(i,1,n)
		mdi=max(mdi,sz(gra2[i]));
	trace(mdi);
	dfs(1,1);
	dfs(1,1,0);
	ans.pop_back();
	cout<<sz(ans)<<endl;
	for(auto i:ans)
		cout<<i.fi<<" "<<i.se<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}