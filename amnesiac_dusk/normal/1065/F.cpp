/*
 * 	If you gave me a chance
 * 		I'll take it
 * 			It's a shot in the dark
 * 				But I will make it:D
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
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
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int p[1000005];
int dp[1000005][2];
int leafy[1000005];
vi gra[1000005];
int tot[1000005];
int n,k;
void dfs(int fr, int at) {
	if(gra[at].empty())
		tot[at]=1;
	else {
		leafy[at]=infi;
		for(int i:gra[at]) {
			dfs(at,i);
			leafy[at]=min(leafy[at],leafy[i]+1);
			tot[at]+=tot[i];
		}
	}
}
void dfs(int at) {
	int mm=0;
	if(gra[at].empty()) {
		dp[at][0]=1;
		dp[at][1]=1;
		return;
	}
	for(int i:gra[at]) {
		dfs(i);
		if(leafy[i]<k) {
			dp[at][0]+=dp[i][0];
			mm=max(mm,dp[i][1]-dp[i][0]);
		} else
			mm=max(mm,dp[i][1]);
	}
	dp[at][1]=dp[at][0]+mm;
}
void solve() {
	cin>>n>>k;
	if(n==1) {
		cout<<0<<endl;
		return;
	}
	for(int i=2; i<=n; i++) {
		cin>>p[i];
		gra[p[i]].pb(i);
	}
	dfs(1,1);
	dfs(1);
//	fr(i,1,n) {
//		cout<<i<<" "<<leafy[i]<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
//	}
	cout<<dp[1][1]<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}