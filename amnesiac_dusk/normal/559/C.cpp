#pragma GCC optimze("Ofast")
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

int fact[200005],ifact[200005];
int ncr(int n, int r) {
	if(n<r||r<0||n<0) return 0;
	return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}
int dp[2005];
void solve() {
	fact[0]=1;
	fr(i,1,200000)
		fact[i]=(fact[i-1]*i)%mod;
	ifact[200000]=powm(fact[200000],mod-2);
	for(int i=199999; i>=0; i--)
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	int h,w,n;
	cin>>h>>w>>n;
	vector<pii> a;
	fr(i,1,n) {
		int ri,ci;
		cin>>ri>>ci;
		a.pb({ri-1,ci-1});
	}
	a.pb({h-1,w-1});
	sort(all(a));
	fr(i,0,n) {
		dp[i]=ncr(a[i].fi+a[i].se,a[i].fi);
		trace(dp[i]);
		rep(j,0,i)
			dp[i]=(dp[i]-dp[j]*ncr(a[i].fi+a[i].se-a[j].fi-a[j].se,a[i].fi-a[j].fi))%mod;
	}
	if(dp[n]<0)
		dp[n]+=mod;
	cout<<dp[n]<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}