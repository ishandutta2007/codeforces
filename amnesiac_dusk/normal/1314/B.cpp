#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
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
// const int mod=998244353;
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

bool fav[1<<17];
int dp[1<<16][4],dp2[1<<16][4];
void solve() {
	int n,k;
	cin>>n>>k;
	n=1<<n;
	rep(i,0,k) {
		int te;
		cin>>te;
		te--;
		fav[te]=1;
	}
	for(int i=0; i<n; i+=2) {
		rep(j,0,4) {
			dp[i>>1][j]=-infi;
			dp2[i>>1][j]=-infi;
		}
		if(fav[i]&&fav[i+1])
			dp[i>>1][3]=1;
		if(fav[i]||fav[i+1]) {
			dp[i>>1][2]=1;
			dp[i>>1][1]=1;
		}
		dp[i>>1][0]=0;
	}
	int nn=n,lol=0;
	while(nn>0) {
		nn>>=1;
		lol++;
	}
	lol-=2;
//	rep(i,0,4) {
//		rep(j,0,4) {
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	rep(ii,0,lol) {
		int pol=lol-ii;
		for(int i=0; i<(1<<pol); i+=2) {
			dp2[i>>1][0]=dp[i][0]+dp[i+1][0];
			dp2[i>>1][1]=dp[i][1]+dp[i+1][1]+2;
			dp2[i>>1][1]=max(dp2[i>>1][1],dp[i][1]+dp[i+1][1]+2);
			dp2[i>>1][1]=max(dp2[i>>1][1],dp[i][0]+dp[i+1][1]+2);
			dp2[i>>1][1]=max(dp2[i>>1][1],dp[i][1]+dp[i+1][0]+2);
			dp2[i>>1][1]=max(dp2[i>>1][1],dp[i][2]+dp[i+1][0]+2);
			dp2[i>>1][1]=max(dp2[i>>1][1],dp[i][0]+dp[i+1][2]+2);
			dp2[i>>1][3]=max(dp2[i>>1][3],dp[i][2]+dp[i+1][2]+2);
			dp2[i>>1][3]=max(dp2[i>>1][3],dp[i][2]+dp[i+1][1]+3);
			dp2[i>>1][3]=max(dp2[i>>1][3],dp[i][1]+dp[i+1][2]+3);
			rep(j,0,4) {
				dp2[i>>1][3]=max(dp2[i>>1][3],dp[i][3]+dp[i+1][j]+3);
				dp2[i>>1][3]=max(dp2[i>>1][3],dp[i][j]+dp[i+1][3]+3);
			}
			dp2[i>>1][2]=max(dp2[i>>1][2],dp[i][2]+dp[i+1][0]+1);
			dp2[i>>1][2]=max(dp2[i>>1][2],dp[i][0]+dp[i+1][2]+1);
		}
		swap(dp,dp2);
		rep(i,0,(1<<(pol-1)))
			rep(j,0,4)
				dp2[i][j]=-infi;
//		cout<<endl;
//		trace(pol);
//		rep(i,0,(1<<(pol-1))) {
//			rep(j,0,4) {
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	int ans=0;
	rep(i,0,4)
		ans=max(ans,dp[0][i]+(i!=0));
	cout<<ans<<endl;
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