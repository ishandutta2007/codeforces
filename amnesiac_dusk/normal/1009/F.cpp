/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
const ll infl=1e12;
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

vi deep[1000005],gra[1000005];
int depth[1000005],ans[1000005];
int dfs(int fr, int at) {
	depth[at]=1;
	int mm=0;
	for(int i:gra[at]) {
		if(i!=fr) {
			dfs(at,i);
			if(depth[i]>depth[mm])
				mm=i;
			depth[at]=max(depth[at],depth[i]+1);
		}
	}
	deep[0].clear();
	deep[0].pb(0);
//	deep[at]=deep[mm];
	swap(deep[at],deep[mm]);
//	trace(at);
	int sm=0;
	for(int i:gra[at]) {
		if(i!=fr&&i!=mm) {
			sm=max(sm,depth[i]);
			for(int j=sz(deep[at])-1,k=sz(deep[i])-1; k>=0; k--,j--)
				deep[at][j]+=deep[i][k];
		}
	}
	ans[at]=ans[mm]+1;
	sm++;
	deep[at].pb(1);
	int an=sz(deep[at])-1-ans[at];
//	trace(at,sm,an,ans[at]);
	for(int i=0; i<sm&&i<sz(deep[at]); i++) {
		int j=sz(deep[at])-1-i;
		if(deep[at][j]>deep[at][an]||(deep[at][j]==deep[at][an]&&j>an)) {
			an=j;
		}
	}
//	trace(at,an);
	ans[at]=sz(deep[at])-1-an;
	return depth[at];
}
void solve() {
	int n;
	cin>>n;
	fr(i,2,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1);
	fr(i,1,n) {
		cout<<ans[i]<<endl;
//		for(int j:deep[i])
//			cout<<j<<" ";
//		cout<<endl;
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