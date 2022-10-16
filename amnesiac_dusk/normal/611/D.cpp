/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=1e12;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int dp[5005][5005];
int zedi[5005];
void getZarr(string str, int Z[]) {
	int n=str.length();
	int L,R,k;
	L=R=0;
	for(int i=1;i<n;++i) {
		if(i>R) {
			L=R=i;
			while(R<n&&str[R-L]==str[R])
				R++;
			Z[i]=R-L;
			R--;
		} else {
			k=i-L;
			if(Z[k]<R-i+1)
				Z[i]=Z[k];
			else {
				L=i;
				while(R<n&&str[R-L]==str[R])
					R++;
				Z[i]=R-L;
				R--;
			}
		}
	}
}
void solve() {
	string s;
	int n;
	cin>>n>>s;
	s='0'+s;
	dp[1][1]=1;
	for(int i=1;i<=n;i++) {
		getZarr(s.substr(i), zedi);
		for(int j=i;j<n;j++) {
			dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			if(s[j+1]!='0') {
				int len=j-i+1;
				bool onep=0;
				if(j+len<=n) {
					int sei=j+1-i;
					if(zedi[sei]>=len) {
						onep=1;
					} else if(s[i+zedi[sei]]>=s[j+1+zedi[sei]]) {
						onep=1;
					}
					if(onep==0) {
						dp[j+1][j+len]=(dp[j+1][j+len]+dp[i][j])%mod;
					} else if(j+len+1<=n) {
						dp[j+1][j+len+1]=(dp[j+1][j+len+1]+dp[i][j])%mod;
					}
				}

			}
		}
	}
	int ans=0;
	fr(i,1,n)
		ans=(ans+dp[i][n])%mod;
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
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}