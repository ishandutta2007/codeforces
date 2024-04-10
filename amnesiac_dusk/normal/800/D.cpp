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
int p2[1000005];
const int pol=(mod+1)/2;
int powm(int a, int b) {
	if(b==-1)
		return pol;
	return p2[b];
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int a0[1000005],a1[1000005],a2[1000005];
int dp[1000005];
int compute(int n) {
	if(n==-1)
		return 0;
	return powm(2,n);
}
void solve() {
	p2[0]=1;
	fr(i,1,1000000)
		p2[i]=(p2[i-1]*2)%mod;
	int n;
	cin>>n;
	fr(i,1,n) {
		int te;
		cin>>te;
		a0[te]++;
		a1[te]+=te;
		a2[te]+=te*te;
	}
	int lol=1;
	for(int i=0; i<6; i++) {
		for(int j=999999; j>=0; j--)
			if((j/lol)%10) {
				a0[j-lol]+=a0[j];
				a1[j-lol]+=a1[j];
				a2[j-lol]+=a2[j];
			}
		lol*=10;
	}
	for(int i=0; i<1000000; i++) {
		if(a0[i]==0)
			continue;
		a0[i]%=mod;
		a1[i]%=mod;
		a2[i]%=mod;
		int lor=powm(2,a0[i]-2);
		dp[i]=((a1[i]*a1[i]+a2[i])%mod*lor)%mod;
	}
	lol=1;
	for(int i=0; i<6; i++) {
		for(int j=0; j<1000000; j++)
			if((j/lol)%10) {
				dp[j-lol]-=dp[j];
				dp[j-lol]%=mod;
			}
		lol*=10;
	}
	int ans=0;
	rep(i,0,1000000) {
		if(dp[i]<0)
			dp[i]+=mod;
		if(dp[i]) {
			trace(i,dp[i],i*dp[i]);
		}
		ans^=i*dp[i];
	}
	cout<<ans<<endl;
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