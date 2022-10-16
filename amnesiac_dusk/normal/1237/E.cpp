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
const int mod=998244353;
//const int mod=1000000007;
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

inline int lo2(int x) {
	return 63-__builtin_clzll(x);
}
int dp[1000005][2];
int h[1000005];
int holve(int n, int par) {
	if(~dp[n][par])
		return dp[n][par];
	int ma=(1<<(h[n]-1))-1,mi=(1<<(h[n]-2))-1;
	int start=max(mi,n-1-ma),end=min(ma,n-1-mi);
	int ans1=0,ans2=0;
	for(int i=start; i<=end; i++) {
		if(i&1)
			ans1=(ans1+holve(i,i&1)*holve(n-i-1,(i+1)&1))%mod;
		else
			ans2=(ans2+holve(i,i&1)*holve(n-i-1,i&1))%mod;
	}
	dp[n][0]=ans1;
	dp[n][1]=ans2;
	return dp[n][par];
}
vi ans={1, 2, 4, 5, 9, 10, 20, 21, 41, 42, 84, 85, 169, 170, 340, 341, 681, 682, 1364, 1365, 2729, 2730, 5460, 5461, 10921, 10922, 21844, 21845, 43689, 43690, 87380, 87381, 174761, 174762, 349524, 349525, 699049, 699050};
void solve() {
//	vi a={1,2};
//	while(a.back()<=100) {
//		a.pb(a[sz(a)-2]*2+1);
//		a.pb(a[sz(a)-3]*2+2);
//	}
//	trace(a);
	int n;
	cin>>n;
	if((*lower_bound(all(ans),n))==n) {
		cout<<1<<endl;
	} else
		cout<<0<<endl;
//	memset(dp,-1,sizeof(dp));
//	dp[1][1]=1;
//	dp[1][0]=0;
//	dp[2][1]=0;
//	dp[2][0]=1;
//	dp[3][0]=0;
//	dp[3][1]=0;
//	int n=1000000;
//	cin>>n;
	fr(i,1,1000000) {
		h[i]=h[i-1];
		if((i&(i-1))==0)
			h[i]++;
	}
	fr(i,1,1000000) {
		if(((holve(i,0)+holve(i,1))%mod)==1)
			cout<<i<<endl;
//		cout<<i<<" #"<<(holve(i,0)+holve(i,1))%mod<<endl;
	}
//	cout<<(holve(n,0)+holve(n,1))%mod<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i, 1, t)
	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}