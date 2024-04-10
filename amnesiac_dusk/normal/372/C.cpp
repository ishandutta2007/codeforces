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
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

vi dp[2];
void solve() {
	int n,m,d;
	cin>>n>>m>>d;
	fr(j,0,1)
		dp[j].resize(n+1,0);
	vector<pair<int,pii>> fw;
	fr(i,1,m) {
		int a,b,t;
		cin>>a>>b>>t;
		fw.pb({t,{a,b}});
	}
	sort(all(fw));
	fw.pb({infi,{infi,infi}});
	for(int i=1; i<=m; i++) {
		deque<pii> opti;
		for(int j=1; j<=n; j++)
			dp[0][j]+=fw[i-1].se.se-abs(fw[i-1].se.fi-j);
		int time=(fw[i].fi-fw[i-1].fi)*d;
		if(time>=n-1) {
			int maxi=-infl;
			fr(j,1,n)
				maxi=max(maxi,dp[0][j]);
			fr(j,1,n)
				dp[1][j]=maxi;
			dp[0].swap(dp[1]);
			continue;
		}
		for(int j=1; j<=time+1; j++) {
			while((!opti.empty())&&opti.back().se<dp[0][j]) {
				opti.pop_back();
			}
			opti.push_back({j+time,dp[0][j]});
		}
		for(int j=1; j<=n; j++) {
			while(opti.front().fi<j)
				opti.pop_front();
			dp[1][j]=opti.front().se;
			while(j+time+1<=n&&(!opti.empty())&&opti.back().se<dp[0][j+time+1]) {
				opti.pop_back();
			}
			if(j+time+1<=n)
				opti.push_back({j+2*time+1,dp[0][j+time+1]});
		}
		dp[0].swap(dp[1]);
	}
//	fr(i,1,m) {
//		fr(j,1,n)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	int ans=-infl;
	fr(i,1,n)
		ans=max(ans,dp[0][i]);
	cout<<ans<<endl;
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