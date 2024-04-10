//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
const ll infl=2e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


const int N=55;
int dp[N][N][N][4];
vi sg[4];
int knap[4][N][N*N];
int fact[N];
int inpe[N];
//int answ[N][N][N][N*N];
void solve() {
	fact[0]=1;
	for(int i=1; i<N; i++)
		fact[i]=(fact[i-1]*i)%mod;
	dp[0][0][0][0]=1;
	for(int i=0; i<=50; i++)
		for(int j=0; j<=50; j++)
			for(int k=0; k<=50; k++) {
				for(int l=0; l<=3; l++)
					if(l!=1) {
						dp[i+1][j][k][1]+=dp[i][j][k][l];
						dp[i+1][j][k][1]%=mod;
					}
				for(int l=0; l<=3; l++)
					if(l!=2) {
						dp[i][j+1][k][2]+=dp[i][j][k][l];
						dp[i][j+1][k][2]%=mod;
					}
				for(int l=0; l<=3; l++)
					if(l!=3) {
						dp[i][j][k+1][3]+=dp[i][j][k][l];
						dp[i][j][k+1][3]%=mod;
					}
			}
	int n,t;
	cin>>n>>t;
	fr(i,1,n) {
		int ti,gi;
		cin>>ti>>gi;
		sg[gi].pb(ti);
	}
	for(int j=1; j<=3; j++) {
		knap[j][0][0]=1;
		for(int i:sg[j]) {
			for(int l=sz(sg[j])-1; l>=0; l--)
				for(int k=t-i; k>=0; k--) {
					knap[j][l+1][k+i]+=knap[j][l][k];
					knap[j][l+1][k+i]%=mod;
				}
		}
	}
	for(int i=1; i<=3; i++)
		for(int j=0; j<=sz(sg[i]); j++)
			for(int k=0; k<=t; k++)
				knap[i][j][k]=(knap[i][j][k]*fact[j])%mod;
	int ans=0;
	for(int i=0; i<=sz(sg[1]); i++) {
		for(int j=0; j<=sz(sg[2]); j++) {
			for(int k=0; k<=sz(sg[3]); k++) {
				for(int l=0; l<=t; l++) {
					for(int m=0; l+m<=t; m++) {
						int o=t-l-m;
						int te=dp[i][j][k][0]+dp[i][j][k][1]+dp[i][j][k][2]+dp[i][j][k][3];
						te=(te*knap[1][i][l])%mod;
						te=(te*knap[2][j][m])%mod;
						te=(te*knap[3][k][o])%mod;
						ans=(ans+te)%mod;
					}
				}
			}
		}
	}
	cout<<ans<<endl;

}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}