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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

char a[51][51];
int dp[51][51][51][51];
int recur(int l1,int l2, int r1, int r2) {
	if(~dp[l1][l2][r1][r2])
		return dp[l1][l2][r1][r2];
	if(l1==l2&&r1==r2) {
		if(a[l1][r1]=='.')
			return dp[l1][l2][r1][r2]=0;
		else
			return dp[l1][l2][r1][r2]=1;
	}
	int ans=max(l2-l1+1,r2-r1+1);
	for(int i=l1; i<l2; i++) {
		ans=min(ans,recur(l1,i,r1,r2)+recur(i+1,l2,r1,r2));
	}
	for(int i=r1; i<r2; i++) {
		ans=min(ans,recur(l1,l2,r1,i)+recur(l1,l2,i+1,r2));
	}
	return dp[l1][l2][r1][r2]=ans;
}
void solve() {
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	fr(i,1,n)
		fr(j,1,n)
			cin>>a[i][j];
	cout<<recur(1,n,1,n)<<endl;
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