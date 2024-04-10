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
const int N=1e6+5;
int a[N],lc[N],mc[N];
int dp[N];
void solve() {
	int n,d,r1,r2,r3;
	cin>>n>>r1>>r2>>r3>>d;
	fr(i,1,n) {
		cin>>a[i];
		mc[i]=min({(a[i]+2)*r1,r1+r2,a[i]*r1+r3});
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	fr(i,1,n) {
		dp[i+1]=min(dp[i+1],dp[i]+r1*a[i]+r3+d);
		dp[i+2]=min(dp[i+2],dp[i]+mc[i]+mc[i+1]+4*d);
		dp[i+3]=min(dp[i+3],dp[i]+mc[i]+mc[i+1]+mc[i+2]+7*d);
	}
	int answer=min({dp[n+1],dp[n+2],dp[n+3],dp[n-1]+3*d+mc[n-1]+mc[n]});
	mc[n]=min({(a[n]+2)*r1+2*d,r1+r2+2*d,a[n]*r1+r3});;
	int runc=0;
	trace(answer);
	for(int i=n; i>0; i--) {
		runc+=mc[i];
		answer=min(answer,dp[i]+runc);
		trace(answer,runc,i,dp[i],mc[i]);
		runc+=2*d;
	}
	cout<<answer<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}