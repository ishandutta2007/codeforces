/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
//#define endl '\n'
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
#define double long double
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
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int dp[200005],dp2[200005];
void solve() {
	int n,a,b;
	cin>>n>>a>>b;
	int gc=gcd(a,b);
	const int msteps=200000;
	fill(dp+1,dp+200001,infl);
	auto cmp=[](int i, int j) {
		return dp[i]<dp[j];
	};
	set<int,decltype(cmp)> bfs(cmp);
	bfs.insert(0);
	while(bfs.size()) {
		int te=*bfs.begin();
		bfs.erase(bfs.begin());
		if(te+a<=msteps) {
			if(dp[te+a]>max(te+a,dp[te])) {
				bfs.erase(te+a);
				dp[te+a]=max(te+a,dp[te]);
				bfs.insert(te+a);
			}
		}
		if(te>b) {
			if(dp[te-b]>dp[te]) {
				bfs.erase(te-b);
				dp[te-b]=dp[te];
				bfs.insert(te-b);
			}
		}
	}
	for(int i=0;i<=msteps;i++) {
		if(dp[i]!=infl)
			dp2[dp[i]]++;
	}
	if(n<=200000) {
		int ans=1;
		for(int i=1;i<=n;i++) {
			dp2[i]+=dp2[i-1];
			ans+=dp2[i];
		}
		cout<<ans<<endl;
		return;
	}
	int ans=1;
	for(int i=1;i<=200000;i++) {
		dp2[i]+=dp2[i-1];
//		cout<<dp2[i]<<endl;
		ans+=dp2[i];
	}
	int i;
	for(i=200001;i<=n;i++) {
		if(i%gc) {
			ans+=1+i/gc;
		} else
			break;
	}
	if(i>n) {
		cout<<ans<<endl;
		return;
	}
	int lol=(n/gc)*gc;
	ans+=(n-lol+1)*(n/gc+1);
	i/=gc;
	lol/=gc;
	ans+=((lol*(lol+1)-i*(i+1))/2)*gc;
	cout<<ans<<endl;
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