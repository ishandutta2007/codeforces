//#pragma GCC optimize("Ofast")
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
#define long long long
//typedef long long ll;
typedef double f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const long infl=2e18;
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
//int powm(ll a, ll b) {
//	int res=1;
//	a%=mod;
//	while(b) {
//		if(b&1)
//			res=(res*a)%mod;
//		a=(a*a)%mod;
//		b>>=1;
//	}
//	return res;
//}
long crt(long p, long m, long q, long n)
	{
		long a = p, b = q;
		long pp = 1, qq = 0;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = pp; pp = qq; qq = d - c * qq;
		}
		if((n - m) % a != 0)return -1;
		long mod = p / a * q;
		long ret = (p * pp % mod * ((n - m) / a) + m) % mod;
		if(ret < 0)ret += mod;
		return ret;
	}

void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	int gc=gcd(n,m);
	fr(i,1,k) {
		int x,y;
		cin>>x>>y;
		long ans=infl,cr;
		cr=crt(2*n,x,2*m,y);
		if(cr>=0)
			ans=min(ans,cr);
		cr=crt(2*n,2*n-x,2*m,y);
		if(cr>=0)
			ans=min(ans,cr);
		cr=crt(2*n,x,2*m,2*m-y);
		if(cr>=0)
			ans=min(ans,cr);
		cr=crt(2*n,2*n-x,2*m,2*m-y);
		if(cr>=0)
			ans=min(ans,cr);
		if(ans==infl)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
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
	fflush(stdout);
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}