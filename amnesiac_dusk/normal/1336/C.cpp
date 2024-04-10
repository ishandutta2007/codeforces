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

int dp[3005][3005];
int dp2[3005][3005];
void solve() {
	string s,t;
	cin>>s>>t;
	int n=sz(s),m=sz(t);
	fr(i,0,sz(t))
		dp2[i][i]=1;
	rep(i,0,sz(t)) {
		for(int j=0; j+i<=sz(t); j++) {
			//[j,j+i)
			if(j&&s[i]==t[j-1]) {
				dp2[j-1][j+i]+=dp2[j][j+i];
				dp2[j-1][j+i]%=mod;
			}
			if(j+i<sz(t)&&s[i]==t[j+i]) {
				dp2[j][j+i+1]+=dp2[j][j+i];
				dp2[j][j+i+1]%=mod;
			}
		}
	}
	trace(dp2[0][sz(t)]);
	reverse(all(t));
	fr(i,0,sz(t)) {
		dp[sz(t)-i][sz(t)-i]=dp2[i][sz(t)];
	}
	t+='$';
	for(int j=0; j<=m; j++) {
		for(int i=j; i<sz(s); i++) {
			if(i!=j&&s[i]==t[j])
				dp[i+1][j+1]+=dp[i][j];
			dp[i+1][j]+=dp[i][j];
			if(j==0)
				dp[i+1][j]+=dp[i][j];
			if(dp[i+1][j+1]>=mod)
				dp[i+1][j+1]-=mod;
			if(dp[i+1][j]>=mod)
				dp[i+1][j]-=mod;
		}
	}
	int ans=0;
	fr(i,1,sz(s)) {
		trace(i,dp[i][m]);
		ans=(ans+dp[i][m])%mod;
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}