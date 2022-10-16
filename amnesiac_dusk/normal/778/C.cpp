#pragma GCC optimize("Ofast")
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


int gra[300005][26];
int ans[300005];
set<int> dp;
void dfs2(vi at, int deep) {
	ans[deep]+=sz(at)-1;
	if(sz(at)<=1)
		return;
	rep(j,0,26) {
		vi polo;
		for(int i:at)
			if(~gra[i][j])
				polo.pb(gra[i][j]);
		if(sz(polo)>1)
			dfs2(polo,deep);
	}
}
void dfs(int at, int deep) {
	ans[deep]++;
	vi pol;
	rep(i,0,26)
		if(~gra[at][i]) {
			pol.pb(gra[at][i]);
			dfs(gra[at][i],deep+1);
		}
	dfs2(pol,deep);
}
void solve() {
	memset(gra,-1,sizeof(gra));
	int n;
	cin>>n;
	fr(i,2,n) {
		int u,v;
		char c;
		cin>>u>>v>>c;
		c-='a';
		gra[u][c]=v;
	}
	dfs(1,1);
	int an1=0;
	fr(i,1,n)
		if(ans[an1]<ans[i])
			an1=i;
	cout<<n-ans[an1]<<endl<<an1<<endl;
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