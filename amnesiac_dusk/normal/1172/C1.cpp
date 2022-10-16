//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
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
const int N=3005;
int a[200005];
int dp[N][N],w[N];
int invert[2*N];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		cin>>a[i];
	}
	int sum=0,good=0,bad=0;
	fr(i,1,n) {
		cin>>w[i];
		if(a[i])
			good+=w[i];
		else
			bad+=w[i];
		sum+=w[i];
	}
	fr(i,3000-m,3000+m) {
		invert[i]=powm(sum+i-3000,mod-2);
	}
	dp[0][0]=1;
	fr(i,0,m) {
		for(int j=0; i+j<m; j++) {
			dp[i+1][j]=(dp[i+1][j]+((dp[i][j]*(good+i))%mod)*invert[3000+i-j])%mod;
			dp[i][j+1]=(dp[i][j+1]+((dp[i][j]*(bad-j))%mod)*invert[3000+i-j])%mod;
		}
	}
	int ansg=0,ansb=0;
	fr(i,0,m) {
		ansg=(ansg+(good+i)*dp[i][m-i])%mod;
		ansb=(ansb+(bad-m+i)*dp[i][m-i])%mod;
	}
	ansg=((ansg*powm(good,mod-2))%mod+mod)%mod;
	ansb=((ansb*powm(bad,mod-2))%mod+mod)%mod;
	fr(i,1,n) {
		if(a[i])
			w[i]=(w[i]*ansg)%mod;
		else
			w[i]=(w[i]*ansb)%mod;
		cout<<w[i]<<endl;
	}



}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(30);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}