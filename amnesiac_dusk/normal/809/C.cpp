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
const ll infl= 0x3f3f3f3f3f3f3f3fLL;
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

int dp[32][2][2][2],dp2[32][2][2][2];
int holve(int xx, int yy, int kk) {
	if(xx<0||yy<0)
		return 0;
	trace(xx,yy,kk);
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	dp[0][1][1][1]=1;
	vi x;
	vi y;
	vi ko;
	fr(i,0,30) {
		x.pb(xx&1);
		y.pb(yy&1);
		ko.pb(kk&1);
		xx>>=1;
		yy>>=1;
		kk>>=1;
	}
	reverse(all(x));
	reverse(all(y));
	reverse(all(ko));
//	kya haal aa gye h zindagi mei ;_;
	fr(i,0,30) {
		//value of coefficients
		rep(j,0,2)
			rep(k,0,2)
				rep(l,0,2)
				//value of variables
					rep(o,0,2) {
						rep(p,0,2) {
							if(j&(x[i]<o)) continue;
							if(k&(y[i]<p)) continue;
							if(l&(ko[i]<(o^p))) continue;
							dp[i+1][j&(x[i]==o)][k&(y[i]==p)][l&(ko[i]==(o^p))]=(dp[i+1][j&(x[i]==o)][k&(y[i]==p)][l&(ko[i]==(o^p))]+dp[i][j][k][l])%mod;
							dp2[i+1][j&(x[i]==o)][k&(y[i]==p)][l&(ko[i]==(o^p))]=(dp2[i+1][j&(x[i]==o)][k&(y[i]==p)][l&(ko[i]==(o^p))]+dp2[i][j][k][l])%mod;
							dp2[i+1][j&(x[i]==o)][k&(y[i]==p)][l&(ko[i]==(o^p))]=(dp2[i+1][j&(x[i]==o)][k&(y[i]==p)][l&(ko[i]==(o^p))]+dp[i][j][k][l]*((o^p)<<(30-i)))%mod;
						}
					}
	}
	int ans=0;
	rep(i,0,2)
		rep(j,0,2)
			rep(k,0,2) {
				ans=(ans+dp2[31][i][j][k]+dp[31][i][j][k])%mod;
			}
	trace(ans);
	return ans;
}
void solve() {
	int x1,x2,y1,y2,k;
	cin>>x1>>y1>>x2>>y2>>k;
	x1--;
	x2--;
	y1--;
	y2--;
	k--;
	trace(x1-1,y1-1,k);
	int ans=holve(x2,y2,k)+holve(x1-1,y1-1,k)-holve(x1-1,y2,k)-holve(x2,y1-1,k);
	ans%=mod;
	if(ans<0)
		ans+=mod;
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}