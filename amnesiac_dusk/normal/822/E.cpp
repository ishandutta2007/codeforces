#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
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
typedef float f80;
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

typedef long long H;
static const H M = 2000000033;
struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};
struct HashInterval {
	vector<K> ha, pw;
	HashInterval(vi& str,H C) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	HashInterval(string& str, H C) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H has(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

int dp[100005][31];
void solve() {
	int n,m,x;
	string s,t;
	cin>>n>>s>>m>>t>>x;
	int b1=chrono::high_resolution_clock::now().time_since_epoch().count()%M;
	HashInterval sh(s,b1),th(t,b1);
	int b2=chrono::high_resolution_clock::now().time_since_epoch().count()%M;
	HashInterval sh2(s,b2),th2(t,b2);
	for(int i=0; i<n; i++) {
		for(int j=0; j<=x; j++)
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		for(int j=0; j<x; j++) {
			int lo=0,hi=min(n-i,m-dp[i][j]),mid=(lo+hi+1)/2;
			while(lo<hi) {
				if(sh.has(i,i+mid)==th.has(dp[i][j],dp[i][j]+mid)) {
					if(sh2.has(i,i+mid)==th2.has(dp[i][j],dp[i][j]+mid))
						lo=mid;
				}
				else
					hi=mid-1;
				mid=(lo+hi+1)/2;
			}
//			trace(i,j,mid);
			dp[i+mid][j+1]=max(dp[i][j]+mid,dp[i+mid][j+1]);
		}
	}
//	fr(i,0,n) {
//		fr(j,0,x)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	fr(i,1,x)
	if(dp[n][i]==m) {
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}