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
typedef double f80;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll,ll> pll;
#define double long double
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
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
	while(b>0) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int dp[20][10][10];
void solve() {
	rep(i,0,10) {
		if(i+1==10) {
			dp[0][i][0]=1;
			dp[0][i][1]=1;
		} else
			dp[0][i][i+1]=1;
	}
	for(int i=1; i<20; i++)
		for(int j=0; j<10; j++)
			for(int k=0; k<10; k++)
				for(int l=0; l<10; l++)
					dp[i][j][l]=(dp[i][j][l]+dp[i-1][j][k]*dp[i-1][k][l])%mod;
	int t=200000;
	cin>>t;
	int fafa=0;
	while(t--) {
//		int n=rng(1e9),m=rng(2e5);
		int n,m;
		cin>>n>>m;
		vi ans(10,0);
		while(n) {
			int te=n%10;
			ans[te]++;
			n/=10;
		}
		for(int i=20; i>=0; i--)
			if((m>>i)&1) {
				vi neans(10,0);
				for(int j=0; j<10; j++)
					for(int k=0; k<10; k++)
						neans[k]=(neans[k]+ans[j]*dp[i][j][k])%mod;
				ans.swap(neans);
			}
		cout<<accumulate(all(ans),0LL)%mod<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}